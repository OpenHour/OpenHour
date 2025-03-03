/*
**	Copyright 2025 OpenHour Contributors & Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

////////////////////////////////////////////////////////////////////////////////
//																																						//
//  (c) 2001-2003 Electronic Arts Inc.																				//
//																																						//
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// FILE: MainMenuUtils.cpp
// Author: Matthew D. Campbell, Sept 2002
// Description: GameSpy version check, patch download, etc utils
///////////////////////////////////////////////////////////////////////////////////////

// INCLUDES ///////////////////////////////////////////////////////////////////////////
#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine

#include <fcntl.h>

//#include "Common/Registry.h"
#include "Common/UserPreferences.h"
#include "Common/Version.h"
#include "GameClient/GameText.h"
#include "GameClient/MessageBox.h"
#include "GameClient/Shell.h"
#include "GameLogic/ScriptEngine.h"

#include "GameClient/ShellHooks.h"

#include "GameNetwork/DownloadManager.h"
#include "GameNetwork/GameSpy/BuddyThread.h"
#include "GameNetwork/GameSpy/MainMenuUtils.h"
#include "GameNetwork/GameSpy/PeerDefs.h"
#include "GameNetwork/GameSpy/PeerThread.h"

#include "WWDownload/Registry.h"
#include "WWDownload/URLBuilder.h"

#ifdef _INTERNAL
// for occasional debugging...
//#pragma optimize("", off)
//#pragma MESSAGE("************************************** WARNING, optimization disabled for debugging purposes")
#endif

///////////////////////////////////////////////////////////////////////////////////////

static Bool checkingForPatchBeforeGameSpy = FALSE;
static Int checksLeftBeforeOnline = 0;
static Int timeThroughOnline = 0; // used to avoid having old callbacks cause problems
static Bool mustDownloadPatch = FALSE;
static Bool cantConnectBeforeOnline = FALSE;
static std::list<QueuedDownload> queuedDownloads;

static char *MOTDBuffer = NULL;
static char *configBuffer = NULL;
GameWindow *onlineCancelWindow = NULL;

static Bool s_asyncDNSThreadDone = TRUE;
static Bool s_asyncDNSThreadSucceeded = FALSE;
static Bool s_asyncDNSLookupInProgress = FALSE;
static HANDLE s_asyncDNSThreadHandle = NULL;
enum {
	LOOKUP_INPROGRESS,
	LOOKUP_FAILED,
	LOOKUP_SUCCEEDED,
};

///////////////////////////////////////////////////////////////////////////////////////

static void startOnline( void );
static void reallyStartPatchCheck( void );

///////////////////////////////////////////////////////////////////////////////////////

// someone has hit a button allowing downloads to start
void StartDownloadingPatches( void )
{
	if (queuedDownloads.empty())
	{
		HandleCanceledDownload();
		return;
	}

	WindowLayout *layout;
	layout = TheWindowManager->winCreateLayout( AsciiString( "Menus/DownloadMenu.wnd" ) );
	layout->runInit();
	layout->hide( FALSE );
	layout->bringForward();
	HandleCanceledDownload(FALSE);
	DEBUG_ASSERTCRASH(TheDownloadManager, ("No download manager!"));
	if (TheDownloadManager)
	{
		std::list<QueuedDownload>::iterator it = queuedDownloads.begin();
		while (it != queuedDownloads.end())
		{
			QueuedDownload q = *it;
			TheDownloadManager->queueFileForDownload(q.server, q.userName, q.password,
				q.file, q.localFile, q.regKey, q.tryResume);
			queuedDownloads.pop_front();
			it = queuedDownloads.begin();
		}
		TheDownloadManager->downloadNextQueuedFile();
	}
}

///////////////////////////////////////////////////////////////////////////////////////

// user agrees to patch before going online
static void patchBeforeOnlineCallback( void )
{
	StartDownloadingPatches();
}

// user doesn't want to patch before going online
static void noPatchBeforeOnlineCallback( void )
{
	queuedDownloads.clear();
	if (mustDownloadPatch || cantConnectBeforeOnline)
	{
		// go back to normal
		HandleCanceledDownload();
	}
	else
	{
		// clear out unneeded downloads and go on
		startOnline();
	}
}

///////////////////////////////////////////////////////////////////////////////////////

static Bool hasWriteAccess()
{
	const char* filename = "PatchAccessTest.txt";	

	remove(filename);

	int handle = _open( filename, _O_CREAT | _O_RDWR, _S_IREAD | _S_IWRITE);
	if (handle == -1)
	{
		return false;
	}

	_close(handle);
	remove(filename);
	
	unsigned int val;
	if (!GetUnsignedIntFromRegistry("", "Version", val))
	{
		return false;
	}

	if (!SetUnsignedIntInRegistry("", "Version", val))
	{
		return false;
	}

	return true;
}

///////////////////////////////////////////////////////////////////////////////////////

static void startOnline( void )
{
	checkingForPatchBeforeGameSpy = FALSE;

	DEBUG_ASSERTCRASH(checksLeftBeforeOnline==0, ("starting online with pending callbacks"));
	if (onlineCancelWindow)
	{
		TheWindowManager->winDestroy(onlineCancelWindow);
		onlineCancelWindow = NULL;
	}

	if (cantConnectBeforeOnline)
	{
		MessageBoxOk(TheGameText->fetch("GUI:CannotConnectToServservTitle"),
			TheGameText->fetch("GUI:CannotConnectToServserv"),
			noPatchBeforeOnlineCallback);
		return;
	}
	if (queuedDownloads.size())
	{
		if (!hasWriteAccess())
		{
			MessageBoxOk(TheGameText->fetch("GUI:Error"),
				TheGameText->fetch("GUI:MustHaveAdminRights"),
				noPatchBeforeOnlineCallback);
		}
		else if (mustDownloadPatch)
		{
			MessageBoxOkCancel(TheGameText->fetch("GUI:PatchAvailable"),
				TheGameText->fetch("GUI:MustPatchForOnline"),
				patchBeforeOnlineCallback, noPatchBeforeOnlineCallback);
		}
		else
		{
			MessageBoxYesNo(TheGameText->fetch("GUI:PatchAvailable"),
				TheGameText->fetch("GUI:CanPatchForOnline"),
				patchBeforeOnlineCallback, noPatchBeforeOnlineCallback);
		}
		return;
	}

	TheScriptEngine->signalUIInteract(TheShellHookNames[SHELL_SCRIPT_HOOK_MAIN_MENU_ONLINE_SELECTED]);

	DEBUG_ASSERTCRASH( !TheGameSpyBuddyMessageQueue, ("TheGameSpyBuddyMessageQueue exists!") );
	DEBUG_ASSERTCRASH( !TheGameSpyPeerMessageQueue, ("TheGameSpyPeerMessageQueue exists!") );
	DEBUG_ASSERTCRASH( !TheGameSpyInfo, ("TheGameSpyInfo exists!") );
	SetUpGameSpy(MOTDBuffer, configBuffer);
	if (MOTDBuffer)
	{
		delete[] MOTDBuffer;
		MOTDBuffer = NULL;
	}
	if (configBuffer)
	{
		delete[] configBuffer;
		configBuffer = NULL;
	}

#ifdef ALLOW_NON_PROFILED_LOGIN
	UserPreferences pref;
	pref.load("GameSpyLogin.ini");
	UserPreferences::const_iterator it = pref.find("useProfiles");
	if (it != pref.end() && it->second.compareNoCase("yes") == 0)
#endif ALLOW_NON_PROFILED_LOGIN
		TheShell->push( AsciiString("Menus/GameSpyLoginProfile.wnd") );
#ifdef ALLOW_NON_PROFILED_LOGIN
	else
		TheShell->push( AsciiString("Menus/GameSpyLoginQuick.wnd") );
#endif ALLOW_NON_PROFILED_LOGIN
}

///////////////////////////////////////////////////////////////////////////////////////

static void queuePatch(Bool mandatory, AsciiString downloadURL)
{
	QueuedDownload q;
	Bool success = TRUE;

	AsciiString connectionType;
	success &= downloadURL.nextToken(&connectionType, ":");

	AsciiString server;
	success &= downloadURL.nextToken(&server, ":/");

	AsciiString user;
	success &= downloadURL.nextToken(&user, ":@");

	AsciiString pass;
	success &= downloadURL.nextToken(&pass, "@/");

	AsciiString filePath;
	success &= downloadURL.nextToken(&filePath, "");

	if (!success && user.isNotEmpty())
	{
		// no user/pass combo - move the file into it's proper place
		filePath = user;
		user = ""; // LFeenanEA - Credentials removed as per Security requirements
		pass = "";
		success = TRUE;
	}

	AsciiString fileStr = filePath;
	const char *s = filePath.reverseFind('/');
	if (s)
		fileStr = s+1;
	AsciiString fileName = "patches\\";
	fileName.concat(fileStr);

	DEBUG_LOG(("download URL split: %d [%s] [%s] [%s] [%s] [%s] [%s]\n",
		success, connectionType.str(), server.str(), user.str(), pass.str(),
		filePath.str(), fileName.str()));

	if (!success)
		return;

	q.file = filePath;
	q.localFile = fileName;
	q.password = pass;
	q.regKey = "";
	q.server = server;
	q.tryResume = TRUE;
	q.userName = user;

	std::list<QueuedDownload>::iterator it = queuedDownloads.begin();
	while (it != queuedDownloads.end())
	{
		if (it->localFile == q.localFile)
			return; // don't add it if it exists already (because we can check multiple times)
		++it;
	}

	queuedDownloads.push_back(q);
}

///////////////////////////////////////////////////////////////////////////////////////

void CancelPatchCheckCallbackAndReopenDropdown( void )
{
	HandleCanceledDownload();
	CancelPatchCheckCallback();
}

void CancelPatchCheckCallback( void )
{
	s_asyncDNSLookupInProgress = FALSE;
	HandleCanceledDownload(FALSE); // don't dropdown
	checkingForPatchBeforeGameSpy = FALSE;
	checksLeftBeforeOnline = 0;
	if (onlineCancelWindow)
	{
		TheWindowManager->winDestroy(onlineCancelWindow);
		onlineCancelWindow = NULL;
	}
	queuedDownloads.clear();
	if (MOTDBuffer)
	{
		delete[] MOTDBuffer;
		MOTDBuffer = NULL;
	}
	if (configBuffer)
	{
		delete[] configBuffer;
		configBuffer = NULL;
	}
}

///////////////////////////////////////////////////////////////////////////////////////

DWORD WINAPI asyncGethostbynameThreadFunc( void * szName )
{
	HOSTENT *he = gethostbyname( (const char *)szName );

	if (he)
	{
		s_asyncDNSThreadSucceeded = TRUE;
	}
	else
	{
		s_asyncDNSThreadSucceeded = FALSE;
	}

	s_asyncDNSThreadDone = TRUE;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////

int asyncGethostbyname(char * szName)
{
	static int            stat = 0;
	static unsigned long  threadid;

	if( stat == 0 )
	{
		/* Kick off gethostname thread */
		s_asyncDNSThreadDone = FALSE;
		s_asyncDNSThreadHandle = CreateThread( NULL, 0, asyncGethostbynameThreadFunc, szName, 0, &threadid );

		if( s_asyncDNSThreadHandle == NULL )
		{
			return( LOOKUP_FAILED );
		}
		stat = 1;
	}
	if( stat == 1 )
	{
		if( s_asyncDNSThreadDone )
		{
			/* Thread finished */
			stat = 0;
			s_asyncDNSLookupInProgress = FALSE;
			s_asyncDNSThreadHandle = NULL;
			return( (s_asyncDNSThreadSucceeded)?LOOKUP_SUCCEEDED:LOOKUP_FAILED );
		}
	}

	return( LOOKUP_INPROGRESS );
}

///////////////////////////////////////////////////////////////////////////////////////

// GameSpy's HTTP SDK has had at least 1 crash bug, so we're going to just bail and
// never try again if they crash us.  We won't be able to get back online again (we'll
// time out) but at least we'll live.
static Bool isHttpOk = TRUE;

void HTTPThinkWrapper( void )
{
}

///////////////////////////////////////////////////////////////////////////////////////

void StopAsyncDNSCheck( void )
{
	if (s_asyncDNSThreadHandle)
	{
#ifdef DEBUG_CRASHING
		Int res =
#endif
			TerminateThread(s_asyncDNSThreadHandle,0);
		DEBUG_ASSERTCRASH(res, ("Could not terminate the Async DNS Lookup thread!"));	// Thread still not killed!
	}
	s_asyncDNSThreadHandle = NULL;
	s_asyncDNSLookupInProgress = FALSE;
}

///////////////////////////////////////////////////////////////////////////////////////

void StartPatchCheck( void )
{
}

///////////////////////////////////////////////////////////////////////////////////////

static void reallyStartPatchCheck( void )
{
	checksLeftBeforeOnline = 4;

	std::string gameURL, mapURL;
	std::string configURL, motdURL;

	FormatURLFromRegistry(gameURL, mapURL, configURL, motdURL);

	std::string proxy;
	if (GetStringFromRegistry("", "Proxy", proxy))
	{
		if (!proxy.empty())
		{
		}
	}

	// check for a patch first
	DEBUG_LOG(("Game patch check: [%s]\n", gameURL.c_str()));
	DEBUG_LOG(("Map patch check: [%s]\n", mapURL.c_str()));
	DEBUG_LOG(("Config: [%s]\n", configURL.c_str()));
	DEBUG_LOG(("MOTD: [%s]\n", motdURL.c_str()));
	
	// check total game stats
	CheckOverallStats();

	// check the users online
	CheckNumPlayersOnline();
}

///////////////////////////////////////////////////////////////////////////////////////
