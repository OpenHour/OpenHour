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
 *                     $Archive:: /Commando/Code/WWAudio/sound3dhandle.h                      $*
 *                                                                                             *
 *                       Author:: Patrick Smith                                                *
 *                                                                                             *
 *                     $Modtime:: 8/13/01 3:11p                                               $*
 *                                                                                             *
 *                    $Revision:: 1                                                           $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __SOUND3DHANDLE_H
#define __SOUND3DHANDLE_H

#include "soundhandle.h"


//////////////////////////////////////////////////////////////////////
//
//	Sound3DHandleClass
//
//////////////////////////////////////////////////////////////////////
class Sound3DHandleClass : public SoundHandleClass
{
public:

	///////////////////////////////////////////////////////////////////
	//	Public constructors/destructors
	///////////////////////////////////////////////////////////////////
	Sound3DHandleClass  (void);
	~Sound3DHandleClass (void);

	///////////////////////////////////////////////////////////////////
	//	Public methods
	///////////////////////////////////////////////////////////////////

	//
	//	RTTI
	//
	Sound3DHandleClass *		As_Sound3DHandleClass (void)	{ return this; }

	//
	//	Handle access
	//
	void*					Get_H3DSAMPLE (void)		{ return SampleHandle; }


	//
	//	Inherited
	//
	void							Set_Miles_Handle (uint32 handle);
	void							Initialize (SoundBufferClass *buffer);
	void							Start_Sample (void);
	void							Stop_Sample (void);
	void							Resume_Sample (void);
	void							End_Sample (void);
	void							Set_Sample_Pan (int pan);
	int							Get_Sample_Pan (void);
	void							Set_Sample_Volume (int volume);
	int							Get_Sample_Volume (void);
	void							Set_Sample_Loop_Count (unsigned int count);
	unsigned int							Get_Sample_Loop_Count (void);
	void							Set_Sample_MS_Position (unsigned int ms);
	void							Get_Sample_MS_Position (int *len, int *pos);
	void							Set_Sample_User_Data (int i, unsigned int val);
	unsigned int							Get_Sample_User_Data (int i);
	int							Get_Sample_Playback_Rate (void);
	void							Set_Sample_Playback_Rate (int rate);
	
protected:
	
	///////////////////////////////////////////////////////////////////
	//	Protected methods
	///////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////
	//	Protected member data
	///////////////////////////////////////////////////////////////////
	void*	SampleHandle;
};


#endif //__SOUND3DHANDLE_H
