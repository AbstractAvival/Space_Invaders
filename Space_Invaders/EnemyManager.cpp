#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	for( auto enemy : enemies )
	{
		enemy = nullptr;
	}
}

EnemyManager::EnemyManager( TextureCodex& textureCodex )
{
	CreateBoss( textureCodex );
	CreateTierOneEnemies( textureCodex );
	CreateTierTwoEnemies( textureCodex );
	CreateTierThreeEnemies( textureCodex );
}

EnemyManager::~EnemyManager()
{
	for( auto enemy : enemies )
	{
		delete enemy;
		enemy = nullptr;
	}

	delete boss;
	boss = nullptr;
}

void EnemyManager::ResetEnemies()
{
}

void EnemyManager::Update()
{
}

void EnemyManager::Render( sf::RenderWindow& window, float interpolation )
{
	for( auto enemy : enemies )
	{
		enemy->Render( window, interpolation );
	}
}

void EnemyManager::CreateTierOneEnemies( TextureCodex& textureCodex )
{
	CreateEnemies( textureCodex, EnemyTypes::TestEnemy, 3, 5 );
}

void EnemyManager::CreateTierTwoEnemies( TextureCodex& textureCodex )
{
	CreateEnemies( textureCodex, EnemyTypes::TestEnemy, 1, 3 );
}

void EnemyManager::CreateTierThreeEnemies( TextureCodex& textureCodex )
{
	CreateEnemies( textureCodex, EnemyTypes::TestEnemy, 0, 1 );
}

void EnemyManager::CreateBoss( TextureCodex& textureCodex )
{
	sf::Vector2< int > enemyPosition = sf::Vector2< int >( -50, -50 );
	boss = new Enemy( textureCodex, EnemyTypes::Boss, enemyPosition );
}

void EnemyManager::CreateEnemies( TextureCodex& textureCodex, EnemyTypes desiredEnemyType, int startingColumn, int endingColumn )
{
	for( int columnIndex = startingColumn; columnIndex < endingColumn; columnIndex++ )
	{
		for( int rowIndex = 0; rowIndex < enemyRowLength; rowIndex++ )
		{
			sf::Vector2< int > enemyPosition = sf::Vector2< int >( ( rowIndex * horizontalSeparationDistance ) + startingXPosition, ( columnIndex * verticalSeparationDistance ) + startingYPosition );
			enemies[ columnIndex * enemyRowLength + rowIndex ] = new Enemy( textureCodex, desiredEnemyType, enemyPosition );
		}
	}
}