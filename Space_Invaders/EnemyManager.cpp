#include "EnemyManager.h"

EnemyManager::EnemyManager( TextureCodex& textureCodex )
{
}

EnemyManager::~EnemyManager()
{
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
}

void EnemyManager::CreateTierTwoEnemies( TextureCodex& textureCodex )
{
}

void EnemyManager::CreateTierThreeEnemies( TextureCodex& textureCodex )
{
	for( int columnIndex = 0; columnIndex == 0; columnIndex++ )
	{
		for( int rowIndex = 0; rowIndex != 11; rowIndex++ )
		{
			//enemies[ columnIndex * enemyRowLength + rowIndex ] =
		}
	}
}

void EnemyManager::CreateBoss( TextureCodex& textureCodex )
{
}
