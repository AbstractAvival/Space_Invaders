#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureCodex.h"
#include "Enemy.h"
using namespace std;

class EnemyManager
{
public:
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

private:
	static constexpr int enemyRowLength = 11;
	static constexpr int enemyColumnHeight = 5;
	static constexpr int horizontalSeparationDistance = 20;
	static constexpr int verticalSeparationDistance = 20;
	static constexpr int startingXPosition = 50;
	static constexpr int startingYPosition = 75;
	GameObject* enemies[ enemyRowLength * enemyColumnHeight ];
	GameObject* boss = nullptr;
};