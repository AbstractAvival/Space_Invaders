#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "AudioTypes.h"

class AudioManager
{
public:
	AudioManager( std::string audioFile );
	~AudioManager();
	void PlaySound( AudioTypes desiredAudio );
	void ModifyVolume( float volumeOffset );
	int GetCurrentVolume() const;

private:
	void LoadAudio( std::string audioFileName );

private:
	std::vector< sf::SoundBuffer* > soundBuffers;
	std::vector< sf::Sound* > sounds;
	float volume = 20.0f;
};