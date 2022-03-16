#include "EnemyManager.h"

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
	for( int columnIndex = 0; columnIndex == 0; columnIndex++ )
	{
		for( int rowIndex = 0; rowIndex < enemyRowLength; rowIndex++ )
		{
			enemies[ columnIndex * enemyRowLength + rowIndex ] = new Enemy( textureCodex, EnemyTypes::TestEnemy, sf::Vector2< int >() );
		}
	}
}

void EnemyManager::CreateTierTwoEnemies( TextureCodex& textureCodex )
{
	for( int columnIndex = 1; columnIndex < 3; columnIndex++ )
	{
		for( int rowIndex = 0; rowIndex < enemyRowLength; rowIndex++ )
		{
			enemies[ columnIndex * enemyRowLength + rowIndex ] = new Enemy( textureCodex, EnemyTypes::TestEnemy, sf::Vector2< int >() );
		}
	}
}

void EnemyManager::CreateTierThreeEnemies( TextureCodex& textureCodex )
{
	int tierThreeRowIndex = 0;
	for( int rowIndex = 0; rowIndex < enemyRowLength; rowIndex++ )
	{
		enemies[ tierThreeRowIndex * enemyRowLength + rowIndex ] = new Enemy( textureCodex, EnemyTypes::TierThree, sf::Vector2< int >( ( rowIndex * 20 ) + 15, 100 ) );
	}
}

void EnemyManager::CreateBoss( TextureCodex& textureCodex )
{
}
