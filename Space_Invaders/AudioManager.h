#pragma once
#include <SFML/Audio.hpp>
#include <vector>
using namespace std;

class AudioManager
{
public:
	AudioManager();
	void PlaySound();

private:
	void LoadSounds();

private:
	vector< sf::SoundBuffer > soundBuffers;
	vector< sf::Sound > sounds;
	sf::Music mainGameMusic;
};