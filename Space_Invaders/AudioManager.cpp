#include "AudioManager.h"

AudioManager::AudioManager( std::string audioFile )
{
	LoadAudio( audioFile );
}

AudioManager::~AudioManager()
{
	for( auto buffer : soundBuffers )
	{
		delete buffer;
		buffer = nullptr;
	}

	for( auto sound : sounds )
	{
		delete sound;
		sound = nullptr;
	}
}

void AudioManager::PlaySound( AudioTypes desiredAudio )
{
	sounds[ int( desiredAudio ) ]->play();
}

void AudioManager::ModifyVolume( float volumeOffset )
{
	volume += volumeOffset;
	for( auto sound : sounds )
	{
		sound->setVolume( volume );
	}
}

int AudioManager::GetCurrentVolume() const
{
	return int( volume );
}

void AudioManager::LoadAudio( std::string audioFileName )
{
	std::string audioName;
	std::vector< std::string > audioNames;
	std::ifstream audioFile( audioFileName );
	if( audioFile.is_open() )
	{
		while( getline( audioFile, audioName ) )
		{
			audioNames.emplace_back( audioName );
		}
		audioFile.close();
	}

	for( int audioIndex = 0; audioIndex < int( audioNames.size() ); audioIndex++ )
	{
		soundBuffers.emplace_back( new sf::SoundBuffer() );
		soundBuffers[ audioIndex ]->loadFromFile( audioNames[ audioIndex ] );
		sounds.emplace_back( new sf::Sound() );
		sounds[ audioIndex ]->setBuffer( *soundBuffers[ audioIndex ] );
		sounds[ audioIndex ]->setVolume( volume );
	}
}