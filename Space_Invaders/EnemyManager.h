#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "TextureCodex.h"
#include "MovementDirections.h"
#include "Enemy.h"
#include "RandomNumberGenerator.h"
#include "HeadsUpDisplay.h"
using namespace std;

class EnemyManager
{
public:
	EnemyManager();
	EnemyManager( TextureCodex& textureCodex, HeadsUpDisplay& hudDisplayIn );
	~EnemyManager();

	void ResetEnemies();
	void UpdateEnemies( float frameTime );
	void RenderEnemies( sf::RenderWindow& window, float interpolation );
	bool CheckCollisionAndKill( sf::FloatRect playerShotBoundary );
	bool IsExecutingOpeningFormation();
	Enemy GetRandomFrontlineEnemy();

private:
	void CreateTierOneEnemies( TextureCodex& textureCodex );
	void CreateTierTwoEnemies( TextureCodex& textureCodex );
	void CreateTierThreeEnemies( TextureCodex& textureCodex );
	void CreateBoss( TextureCodex& textureCodex);
	void CreateEnemies( TextureCodex& textureCodex, EnemyTypes desiredEnemyType, int startingColumn, int endingColumn );
	void HandleEnemyMovement( float frameTime );
	void ResetEnemyPositions();
	void DoOpeningFormation();
	void MoveEnemies( sf::Vector2f direction );
	void SetMovementDirection();
	void ClearExplodedEnemies();
	sf::Vector2f GetMovementVector();

private:
	static constexpr int enemyRowLength = 11;
	static constexpr int enemyColumnHeight = 5;
	static constexpr int explodedValue = 2;
	static constexpr float horizontalSeparationDistance = 40.0f;
	static constexpr float verticalSeparationDistance = 35.0f;
	static constexpr float startingXPosition = 50.0f;
	static constexpr float startingYPosition = 130.0f;
	Enemy* enemies[ enemyRowLength * enemyColumnHeight ];
	Enemy* boss = nullptr;
	HeadsUpDisplay* hudDisplay = nullptr;
	MovementDirections currentMovementDirection;
	RandomNumberGenerator numberGenerator;
	bool isExecutingOpeningFormation = true;
	bool isGoingLeft = false;
	float maxFrameTime = 0.13f;
	float accumulatedFrameTime = 0.0f;
	int horizontalMovementCount = 14;
	int verticalMovementCount = 1;
	int openingFormationX;
	int openingFormationY;
	int movementColumnIndex;
	int movementXIndex;
	int movementYIndex;
};