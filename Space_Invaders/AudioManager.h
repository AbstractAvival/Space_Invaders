#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include "AudioTypes.h"
using namespace std;

class AudioManager
{
public:
	AudioManager();
	void PlaySound( AudioTypes desiredAudio );

private:
	void LoadSounds();

private:
	vector< sf::SoundBuffer > soundBuffers;
	vector< sf::Sound > sounds;
	sf::Music mainGameMusic;
};