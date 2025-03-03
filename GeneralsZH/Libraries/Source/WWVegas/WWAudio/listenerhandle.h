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

/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : wwaudio                                                      *
 *                                                                                             *
 *                     $Archive:: /Commando/Code/WWAudio/listenerhandle.h                     $*
 *                                                                                             *
 *                       Author:: Patrick Smith                                                *
 *                                                                                             *
 *                     $Modtime:: 8/13/01 11:54a                                              $*
 *                                                                                             *
 *                    $Revision:: 1                                                           $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __LISTENERHANDLE_H
#define __LISTENERHANDLE_H

#include "sound3dhandle.h"


//////////////////////////////////////////////////////////////////////
//
//	ListenerHandleClass
//
//////////////////////////////////////////////////////////////////////
class ListenerHandleClass : public Sound3DHandleClass
{
public:

	///////////////////////////////////////////////////////////////////
	//	Public constructors/destructors
	///////////////////////////////////////////////////////////////////
	ListenerHandleClass  (void);
	~ListenerHandleClass (void);

	///////////////////////////////////////////////////////////////////
	//	Public methods
	///////////////////////////////////////////////////////////////////

	//
	//	RTTI
	//
	ListenerHandleClass *	As_ListenerHandleClass (void)		{ return this; }

	//
	//	Inherited
	//
	void							Initialize (SoundBufferClass *buffer) {}
	void							Start_Sample (void)									{ }
	void							Stop_Sample (void)									{ }
	void							Resume_Sample (void)									{ }
	void							End_Sample (void)										{ }
	void							Set_Sample_Volume (int volume)					{ }
	int							Get_Sample_Volume (void)							{ return 0; }
	void							Set_Sample_Pan (int pan)							{ }
	int							Get_Sample_Pan (void)								{ return 64; }
	void							Set_Sample_Loop_Count (unsigned int count)				{ }
	unsigned int							Get_Sample_Loop_Count (void)						{ return 0; }
	void							Set_Sample_MS_Position (unsigned int ms)					{ }
	void							Get_Sample_MS_Position (int *len, int *pos)	{ }
	int							Get_Sample_Playback_Rate (void)					{ return 0; }
	void							Set_Sample_Playback_Rate (int rate)				{ }
	
protected:
	
	///////////////////////////////////////////////////////////////////
	//	Protected methods
	///////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////
	//	Protected member data
	///////////////////////////////////////////////////////////////////
};


#endif //__LISTENERHANDLE_H
