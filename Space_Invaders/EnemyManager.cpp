#include "EnemyManager.h"

EnemyManager::EnemyManager()
	:
	executingOpeningAnimation( true ),
	initializationX( enemyRowLength - 1 ),
	initializationY( enemyColumnHeight - 1 )
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
	ResetEnemyPositions();
	executingOpeningAnimation = true;
	initializationX = enemyRowLength - 1;
	initializationY = enemyColumnHeight - 1;
}

void EnemyManager::UpdateEnemies()
{
	DoOpeningAnimation();
}

void EnemyManager::RenderEnemies( sf::RenderWindow& window, float interpolation )
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
	sf::Vector2< float > enemyPosition = sf::Vector2< float >( -50.0f, -50.0f );
	boss = new Enemy( textureCodex, EnemyTypes::Boss, enemyPosition );
}

void EnemyManager::CreateEnemies( TextureCodex& textureCodex, EnemyTypes desiredEnemyType, int startingColumn, int endingColumn )
{
	for( int columnIndex = startingColumn; columnIndex < endingColumn; columnIndex++ )
	{
		for( int rowIndex = 0; rowIndex < enemyRowLength; rowIndex++ )
		{
			sf::Vector2< float > enemyPosition = sf::Vector2< float >( ( rowIndex * horizontalSeparationDistance ) + startingXPosition, ( columnIndex * verticalSeparationDistance ) + startingYPosition );
			enemies[ columnIndex * enemyRowLength + rowIndex ] = new Enemy( textureCodex, desiredEnemyType, enemyPosition );
			enemies[ columnIndex * enemyRowLength + rowIndex ]->Kill();
		}
	}
}

void EnemyManager::ResetEnemyPositions()
{
	for( int columnIndex = 0; columnIndex < enemyColumnHeight; columnIndex++ )
	{
		for( int rowIndex = 0; rowIndex < enemyRowLength; rowIndex++ )
		{
			sf::Vector2< float > enemyPosition = sf::Vector2< float >( ( rowIndex * horizontalSeparationDistance ) + startingXPosition, ( columnIndex * verticalSeparationDistance ) + startingYPosition );
			enemies[ columnIndex * enemyRowLength + rowIndex ]->SetPosition( enemyPosition );
		}
	}
}

void EnemyManager::DoOpeningAnimation()
{
	if( executingOpeningAnimation )
	{
		enemies[ initializationY * enemyRowLength + initializationX ]->Revive();
		initializationX -= 1;

		if( initializationX < 0 )
		{
			initializationX = enemyRowLength - 1;
			initializationY -= 1;
		}

		if( initializationY < 0 )
			executingOpeningAnimation = false;
	}
}