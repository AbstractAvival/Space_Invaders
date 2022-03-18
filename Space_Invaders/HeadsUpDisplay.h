#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "TextureCodex.h"
using namespace std;

class HeadsUpDisplay
{
public:
	HeadsUpDisplay( TextureCodex& textureCodex );
	void ModifyScore( int scoreOffset );
	void ModifyLives( int lifeOffset );

private:
	void LoadHighScore();
	void InitializeScoreDisplays();
	void InitializeLivesDisplay();

private:
	vector< sf::Text > scoreSprites;
	vector< sf::Sprite > lives;
	int highScore;
	int currentScore;
	int lives;
};