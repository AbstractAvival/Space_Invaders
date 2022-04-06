#pragma once
#include <SFML/Graphics.hpp>
#include "TextureCodex.h"
#include "EnemyTypes.h"
#include "AudioManager.h"

class HeadsUpDisplay
{
public:
	HeadsUpDisplay( TextureCodex& textureCodex, AudioManager& audioManagerIn, std::string highScoreFileName );
	void UpdateHUD();
	void RenderHUD( sf::RenderWindow& window );
	void ModifyScore( EnemyTypes killedEnemyType );
	void ModifyLives( int lifeOffset );
	void ResetHUD();
	bool IsGameOver();
	int GetCurrentLives() const;

private:
	void LoadHighScore( std::string fileName );
	void SaveHighScore();
	void UpdateHighScore();
	void CheckIfEarnedNewLife();
	void InitializeDisplayPositions();
	void InitializeScoreDisplays( TextureCodex& textureCodex );
	void InitializeLivesDisplay( TextureCodex& textureCodex );

private:
	std::vector< sf::Text > scoreFonts;
	std::vector< sf::Sprite > lives;
	std::vector< sf::Vector2f > displayPositions;
	AudioManager* audioManager = nullptr;
	std::string highScoreFileName;
	const int characterSize = 15;
	const int maxScoreDisplays = 4;
	const int maxLives = 5;
	int requiredNewLifeScore = 1000;
	int accumulatedLifeScore = 0;
	int highScore;
	int currentScore;
	int currentLives;
};