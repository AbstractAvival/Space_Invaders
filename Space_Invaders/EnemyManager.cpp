#include "EnemyManager.h"

EnemyManager::EnemyManager( TextureCodex& textureCodex )
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
}

void EnemyManager::CreateBoss( TextureCodex& textureCodex )
{
}
