#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureCodex.h"
#include "MovementDirections.h"
#include "Enemy.h"
using namespace std;

class EnemyManager
{
public:
	EnemyManager();
	EnemyManager( TextureCodex& textureCodex );
	~EnemyManager();

	void ResetEnemies();
	void UpdateEnemies( float frameTime );
	void RenderEnemies( sf::RenderWindow& window, float interpolation );

private:
	void CreateTierOneEnemies( TextureCodex& textureCodex );
	void CreateTierTwoEnemies( TextureCodex& textureCodex );
	void CreateTierThreeEnemies( TextureCodex& textureCodex );
	void CreateBoss( TextureCodex& textureCodex);
	void CreateEnemies( TextureCodex& textureCodex, EnemyTypes desiredEnemyType, int startingColumn, int endingColumn );
	void HandleEnemyMovement( float frameTime );
	void ResetEnemyPositions();
	void DoOpeningFormation();
	void MoveEnemies( sf::Vector2< float > direction );
	void SetMovementDirection();
	sf::Vector2< float > GetMovementVector();

private:
	static constexpr int enemyRowLength = 11;
	static constexpr int enemyColumnHeight = 5;
	static constexpr float horizontalSeparationDistance = 45.0f;
	static constexpr float verticalSeparationDistance = 40.0f;
	static constexpr float startingXPosition = 50.0f;
	static constexpr float startingYPosition = 75.0f;
	GameObject* enemies[ enemyRowLength * enemyColumnHeight ];
	GameObject* boss = nullptr;
	MovementDirections currentMovementDirection;
	bool executingOpeningFormation = true;
	bool isGoingLeft = false;
	float maxFrameTime = 0.2f;
	float accumulatedFrameTime = 0.0f;
	int horizontalMovementCount = 11;
	int verticalMovementCount = 1;
	int openingFormationX;
	int openingFormationY;
	int movementColumnIndex;
	int movementXIndex;
	int movementYIndex;
};