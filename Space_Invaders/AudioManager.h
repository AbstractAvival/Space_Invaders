#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "AudioTypes.h"
using namespace std;

class AudioManager
{
public:
	AudioManager( string audioFile );
	~AudioManager();
	void PlaySound( AudioTypes desiredAudio );

private:
	void LoadAudio( string audioFileName );

private:
	vector< sf::SoundBuffer* > soundBuffers;
	vector< sf::Sound* > sounds;
	float volume = 50.0f;
};