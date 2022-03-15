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

	void ResetEnemies();
	void Update();
	void Render( sf::RenderWindow& window, float interpolation );

private:
	void CreateTierOneEnemies( TextureCodex& textureCodex );
	void CreateTierTwoEnemies( TextureCodex& textureCodex );
	void CreateTierThreeEnemies( TextureCodex& textureCodex );
	void CreateBoss( TextureCodex& textureCodex);

private:
	static constexpr int enemyRowLength = 11;
	static constexpr int enemyColumnHeight = 5;
	GameObject* enemies[ enemyRowLength * enemyColumnHeight ];
	GameObject* boss;
};