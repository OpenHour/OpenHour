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
#pragma once

#include "Common/AsciiString.h"
#include "Common/GameAudio.h"

class DummyAudioManager final: public AudioManager {
public:
#if defined(_DEBUG) || defined(_INTERNAL)
	void audioDebugDisplay(DebugDisplayInterface *dd, void *userData, FILE *fp = NULL ) override {}
#endif

	void stopAudio( AudioAffect which ) override {}
	void pauseAudio( AudioAffect which ) override {}
    void resumeAudio( AudioAffect which ) override {}
	void pauseAmbient( Bool shouldPause ) override {}

	void stopAllAmbientsBy( Object* obj ) override {}
	void stopAllAmbientsBy( Drawable* draw ) override {}

	void killAudioEventImmediately( AudioHandle audioEvent ) override {}

	void nextMusicTrack( void ) override {}
	void prevMusicTrack( void ) override {}
	Bool isMusicPlaying( void ) const override { return false; }
	Bool hasMusicTrackCompleted( const AsciiString& trackName, Int numberOfTimes ) const override { return false; }
	AsciiString getMusicTrackName( void ) const override { return {}; }

	void openDevice( void ) override {}
	void closeDevice( void ) override {}
	void *getDevice( void ) override { return nullptr; }

	void notifyOfAudioCompletion( UnsignedInt audioCompleted, UnsignedInt flags ) override {}

	UnsignedInt getProviderCount( void ) const override { return 0; }
	AsciiString getProviderName( UnsignedInt providerNum ) const override { return {}; }
	UnsignedInt getProviderIndex( AsciiString providerName ) const override { return 0; }
	void selectProvider( UnsignedInt providerNdx ) override {}
	void unselectProvider( void ) override {}
	UnsignedInt getSelectedProvider( void ) const override { return 0; }
	void setSpeakerType( UnsignedInt speakerType ) override {}
	UnsignedInt getSpeakerType( void ) override { return 0; }

	UnsignedInt getNum2DSamples( void ) const override { return 0; }
	UnsignedInt getNum3DSamples( void ) const override { return 0; }
	UnsignedInt getNumStreams( void ) const override { return 0; }

	Bool doesViolateLimit( AudioEventRTS *event ) const override { return true; }
	Bool isPlayingLowerPriority( AudioEventRTS *event ) const override { return false; }
	Bool isPlayingAlready( AudioEventRTS *event ) const override { return true; }
	Bool isObjectPlayingVoice( UnsignedInt objID ) const override { return true; }

	void adjustVolumeOfPlayingAudio(AsciiString eventName, Real newVolume) override {}
	void removePlayingAudio( AsciiString eventName ) override {}
	void removeAllDisabledAudio() override {}

	void *getHandleForBink( void ) override { return nullptr; }
	void releaseHandleForBink( void ) override { }

	void friend_forcePlayAudioEventRTS(const AudioEventRTS* eventToPlay) override {}

	void setListenerPosition( const Coord3D *newListenerPos, const Coord3D *newListenerOrientation ) override {}
	const Coord3D *getListenerPosition( void ) const override { return &m_listenerPosition; }

	void setPreferredProvider(AsciiString providerNdx) override {}
	void setPreferredSpeaker(AsciiString speakerType) override {}

	Real getFileLengthMS( AsciiString strToLoad ) const override { return 0.f; }

	void closeAnySamplesUsingFile( const void *fileToClose ) override {}

protected:
	void setDeviceListenerPosition( void ) override {}

private:
	Coord3D m_listenerPosition;
};