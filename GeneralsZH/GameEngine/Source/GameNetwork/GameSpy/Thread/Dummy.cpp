/*
**	Copyright 2025 OpenHour Contributors.
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
#include <GameNetwork/GameSpy/BuddyThread.h>
#include <GameNetwork/GameSpy/GameResultsThread.h>
#include <GameNetwork/GameSpy/PeerThread.h>
#include <GameNetwork/GameSpy/PersistentStorageThread.h>
#include <GameNetwork/GameSpy/PingThread.h>

GameSpyBuddyMessageQueueInterface* TheGameSpyBuddyMessageQueue = nullptr;
GameResultsInterface* TheGameResultsQueue = nullptr;
GameSpyPeerMessageQueueInterface* TheGameSpyPeerMessageQueue = nullptr;
GameSpyPSMessageQueueInterface *TheGameSpyPSMessageQueue = nullptr;
PingerInterface* ThePinger = nullptr;

GameSpyBuddyMessageQueueInterface* GameSpyBuddyMessageQueueInterface::createNewMessageQueue()
{
	return nullptr;
}

GameResultsInterface* GameResultsInterface::createNewGameResultsInterface()
{
  	return nullptr;
}

GameSpyPeerMessageQueueInterface* GameSpyPeerMessageQueueInterface::createNewMessageQueue()
{
	return nullptr;
}

GameSpyPSMessageQueueInterface* GameSpyPSMessageQueueInterface::createNewMessageQueue()
{
	return nullptr;
}

PingerInterface* PingerInterface::createNewPingerInterface()
{
	return nullptr;
}

PSRequest::PSRequest() = default;

PSPlayerStats::PSPlayerStats() = default;
PSPlayerStats::PSPlayerStats(PSPlayerStats const&) = default;

void PSPlayerStats::reset() {}

std::string GameSpyPSMessageQueueInterface::formatPlayerKVPairs( PSPlayerStats stats ) {
	return {};
}

PSPlayerStats GameSpyPSMessageQueueInterface::parsePlayerKVPairs( std::string kvPairs ) {
	return {};
}

int isThreadHosting = 0;

extern "C" {
int getQR2HostingStatus(void) { return 0; }
}