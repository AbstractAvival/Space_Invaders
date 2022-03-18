#pragma once
#include <SFML/Graphics.hpp>
#include "TextureCodex.h"
using namespace std;

class HeadsUpDisplay
{
public:
	HeadsUpDisplay( TextureCodex& textureCodex, string highScoreFileName );
	void UpdateHUD();
	void RenderHUD( sf::RenderWindow& window );
	void ModifyScore( int scoreOffset );
	void ModifyLives( int lifeOffset );

private:
	void LoadHighScore( string fileName );
	void InitializeDisplayPositions();
	void InitializeScoreDisplays( TextureCodex& textureCodex );
	void InitializeLivesDisplay( TextureCodex& textureCodex );

private:
	vector< sf::Text > scoreFonts;
	vector< sf::Sprite > lives;
	vector< sf::Vector2< float > > displayPositions;
	const int maxScoreDisplays = 4;
	const int maxLives = 5;
	int highScore;
	int currentScore;
	int currentlives;
};