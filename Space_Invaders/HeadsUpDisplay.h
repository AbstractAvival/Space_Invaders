#pragma once
#include <SFML/Graphics.hpp>
#include "TextureCodex.h"
#include "EnemyTypes.h"
using namespace std;

class HeadsUpDisplay
{
public:
	HeadsUpDisplay( TextureCodex& textureCodex, string highScoreFileName );
	void UpdateHUD();
	void RenderHUD( sf::RenderWindow& window );
	void ModifyScore( EnemyTypes killedEnemyType );
	void ModifyLives( int lifeOffset );
	int GetCurrentLives() const;

private:
	void LoadHighScore( string fileName );
	void SaveHighScore();
	void UpdateHighScore();
	void InitializeDisplayPositions();
	void InitializeScoreDisplays( TextureCodex& textureCodex );
	void InitializeLivesDisplay( TextureCodex& textureCodex );

private:
	vector< sf::Text > scoreFonts;
	vector< sf::Sprite > lives;
	vector< sf::Vector2f > displayPositions;
	string highScoreFileName;
	const int characterSize = 15;
	const int maxScoreDisplays = 4;
	const int maxLives = 5;
	int highScore;
	int currentScore;
	int currentlives;
};