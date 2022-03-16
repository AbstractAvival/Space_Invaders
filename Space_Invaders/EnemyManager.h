#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureCodex.h"
#include "Enemy.h"
using namespace std;

class EnemyManager
{
public:
	EnemyManager();
	EnemyManager( TextureCodex& textureCodex );
	~EnemyManager();

	void ResetEnemies();
	void Update();
	void Render( sf::RenderWindow& window, float interpolation );

private:
	void CreateTierOneEnemies( TextureCodex& textureCodex );
	void CreateTierTwoEnemies( TextureCodex& textureCodex );
	void CreateTierThreeEnemies( TextureCodex& textureCodex );
	void CreateBoss( TextureCodex& textureCodex);
	void CreateEnemies( TextureCodex& textureCodex, EnemyTypes desiredEnemyType, int startingColumn, int endingColumn );
	void ResetEnemyPositions();
	void DoOpeningAnimation();

private:
	static constexpr int enemyRowLength = 11;
	static constexpr int enemyColumnHeight = 5;
	static constexpr float horizontalSeparationDistance = 45.0f;
	static constexpr float verticalSeparationDistance = 40.0f;
	static constexpr float startingXPosition = 50.0f;
	static constexpr float startingYPosition = 75.0f;
	GameObject* enemies[ enemyRowLength * enemyColumnHeight ];
	GameObject* boss = nullptr;
	bool executingOpeningAnimation;
	int initializationX;
	int initializationY;
};