#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"
using namespace std;

class EnemyManager
{
public:
	EnemyManager();

	void ResetEnemies();
	void Update();
	void Render( sf::RenderWindow& window, float interpolation );

private:
	static constexpr int enemyRowLength = 11;
	static constexpr int enemyColumnHeight = 5;
	GameObject* enemies[ enemyRowLength * enemyColumnHeight ];
};