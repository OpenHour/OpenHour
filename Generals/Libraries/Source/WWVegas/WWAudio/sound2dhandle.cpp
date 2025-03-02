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
 *                     $Archive:: /Commando/Code/WWAudio/sound2dhandle.cpp        $*
 *                                                                                             *
 *                       Author:: Patrick Smith                                                *
 *                                                                                             *
 *                     $Modtime:: 8/23/01 5:07p                                               $*
 *                                                                                             *
 *                    $Revision:: 2                                                           $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "sound2dhandle.h"
#include "audiblesound.h"


//////////////////////////////////////////////////////////////////////
//
//	Sound2DHandleClass
//
//////////////////////////////////////////////////////////////////////
Sound2DHandleClass::Sound2DHandleClass (void)	:
	SampleHandle (nullptr)
{
	return ;
}


//////////////////////////////////////////////////////////////////////
//
//	~Sound2DHandleClass
//
//////////////////////////////////////////////////////////////////////
Sound2DHandleClass::~Sound2DHandleClass (void)
{
	return ;
}


//////////////////////////////////////////////////////////////////////
//
//	Initialize
//
//////////////////////////////////////////////////////////////////////
void
Sound2DHandleClass::Initialize (SoundBufferClass *buffer)
{
	SoundHandleClass::Initialize (buffer);

	if (SampleHandle != nullptr) {

		//
		// Make sure this handle is fresh
		//
		//::AIL_init_sample (SampleHandle);

		//
		// Pass the actual sound data onto the sample
		//
		//if (Buffer != NULL) {
		//	::AIL_set_named_sample_file (SampleHandle, (char *)Buffer->Get_Filename (),
		//			Buffer->Get_Raw_Buffer (), Buffer->Get_Raw_Length (), 0);
		//}
	}

	return ;
}


//////////////////////////////////////////////////////////////////////
//
//	Start_Sample
//
//////////////////////////////////////////////////////////////////////
void
Sound2DHandleClass::Start_Sample (void)
{
	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	::AIL_start_sample (SampleHandle);
	//}

	return ;
}


//////////////////////////////////////////////////////////////////////
//
//	Stop_Sample
//
//////////////////////////////////////////////////////////////////////
void
Sound2DHandleClass::Stop_Sample (void)
{
	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	::AIL_stop_sample (SampleHandle);
	//}

	return ;
}


//////////////////////////////////////////////////////////////////////
//
//	Resume_Sample
//
//////////////////////////////////////////////////////////////////////
void
Sound2DHandleClass::Resume_Sample (void)
{
	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	::AIL_resume_sample (SampleHandle);
	//}

	return ;
}


//////////////////////////////////////////////////////////////////////
//
//	End_Sample
//
//////////////////////////////////////////////////////////////////////
void
Sound2DHandleClass::End_Sample (void)
{
	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	::AIL_end_sample (SampleHandle);
	//}

	return ;
}


//////////////////////////////////////////////////////////////////////
//
//	Set_Sample_Pan
//
//////////////////////////////////////////////////////////////////////
void
Sound2DHandleClass::Set_Sample_Pan (int32_t pan)
{
	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	::AIL_set_sample_pan (SampleHandle, pan);
	//}

	return ;
}


//////////////////////////////////////////////////////////////////////
//
//	Get_Sample_Pan
//
//////////////////////////////////////////////////////////////////////
int32_t
Sound2DHandleClass::Get_Sample_Pan (void)
{
	int32_t retval = 0;

	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	retval = ::AIL_sample_pan (SampleHandle);
	//}

	return retval;
}


//////////////////////////////////////////////////////////////////////
//
//	Set_Sample_Volume
//
//////////////////////////////////////////////////////////////////////
void
Sound2DHandleClass::Set_Sample_Volume (int32_t volume)
{
	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	::AIL_set_sample_volume (SampleHandle, volume);
	//}
}


//////////////////////////////////////////////////////////////////////
//
//	Get_Sample_Volume
//
//////////////////////////////////////////////////////////////////////
int32_t
Sound2DHandleClass::Get_Sample_Volume (void)
{
	int32_t retval = 0;

	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	retval = ::AIL_sample_volume (SampleHandle);
	//}

	return retval;
}


//////////////////////////////////////////////////////////////////////
//
//	Set_Sample_Loop_Count
//
//////////////////////////////////////////////////////////////////////
void
Sound2DHandleClass::Set_Sample_Loop_Count (uint32_t count)
{
	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	::AIL_set_sample_loop_count (SampleHandle, count);
	//}
}


//////////////////////////////////////////////////////////////////////
//
//	Get_Sample_Loop_Count
//
//////////////////////////////////////////////////////////////////////
uint32_t
Sound2DHandleClass::Get_Sample_Loop_Count (void)
{
	uint32_t retval = 0;

	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	retval = ::AIL_sample_loop_count (SampleHandle);
	//}

	return retval;
}


//////////////////////////////////////////////////////////////////////
//
//	Set_Sample_MS_Position
//
//////////////////////////////////////////////////////////////////////
void
Sound2DHandleClass::Set_Sample_MS_Position (uint32_t ms)
{
	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	::AIL_set_sample_ms_position (SampleHandle, ms);
	//}
}


//////////////////////////////////////////////////////////////////////
//
//	Get_Sample_MS_Position
//
//////////////////////////////////////////////////////////////////////
void
Sound2DHandleClass::Get_Sample_MS_Position (int32_t *len, int32_t *pos)
{
	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	::AIL_sample_ms_position (SampleHandle, len, pos);
	//}
}


//////////////////////////////////////////////////////////////////////
//
//	Set_Sample_User_Data
//
//////////////////////////////////////////////////////////////////////
void
Sound2DHandleClass::Set_Sample_User_Data (int32_t i, uint32_t val)
{
	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	::AIL_set_sample_user_data (SampleHandle, i, val);
	//}
}


//////////////////////////////////////////////////////////////////////
//
//	Get_Sample_User_Data
//
//////////////////////////////////////////////////////////////////////
uint32_t
Sound2DHandleClass::Get_Sample_User_Data (int32_t i)
{
	uint32_t retval = 0;

	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	retval = ::AIL_sample_user_data (SampleHandle, i);
	//}

	return retval;
}


//////////////////////////////////////////////////////////////////////
//
//	Get_Sample_Playback_Rate
//
//////////////////////////////////////////////////////////////////////
int32_t
Sound2DHandleClass::Get_Sample_Playback_Rate (void)
{	
	int32_t retval = 0;

	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	retval = ::AIL_sample_playback_rate (SampleHandle);
	//}

	return retval;
}


//////////////////////////////////////////////////////////////////////
//
//	Set_Sample_Playback_Rate
//
//////////////////////////////////////////////////////////////////////
void
Sound2DHandleClass::Set_Sample_Playback_Rate (int32_t rate)
{
	//if (SampleHandle != (HSAMPLE)INVALID_MILES_HANDLE) {
	//	::AIL_set_sample_playback_rate (SampleHandle, rate);
	//}
}


//////////////////////////////////////////////////////////////////////
//
//	Set_Miles_Handle
//
//////////////////////////////////////////////////////////////////////
void
Sound2DHandleClass::Set_Miles_Handle (uint32 handle)
{
	SampleHandle = (void*)handle;
	return ;
}
