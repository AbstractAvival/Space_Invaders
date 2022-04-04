#include "AudioManager.h"

AudioManager::AudioManager( string audioFile, string musicFile )
{
	LoadAudio( audioFile, musicFile );
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
}

void AudioManager::PlayBackgroundMusic()
{
}

void AudioManager::StopBackgroundMusic()
{
}

void AudioManager::LoadAudio( string audioFileName, string musicFileName )
{
	string audioName;
	vector< string > audioNames;
	ifstream audioFile( audioFileName );
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
	}

	mainGameMusic.openFromFile( musicFileName );
}
