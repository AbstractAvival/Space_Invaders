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
	AudioManager( string audioFile, string musicFile );
	~AudioManager();
	void PlaySound( AudioTypes desiredAudio );
	void PlayBackgroundMusic();
	void StopBackgroundMusic();

private:
	void LoadAudio( string audioFileName, string musicFileName );

private:
	vector< sf::SoundBuffer* > soundBuffers;
	vector< sf::Sound* > sounds;
	sf::Music mainGameMusic;
};