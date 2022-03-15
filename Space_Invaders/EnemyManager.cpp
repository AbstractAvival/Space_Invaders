#include "EnemyManager.h"

EnemyManager::EnemyManager()
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