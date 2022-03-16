#include "EnemyManager.h"

EnemyManager::EnemyManager()
	:
	openingFormationX( enemyRowLength - 1 ),
	openingFormationY( enemyColumnHeight - 1 ),
	movementXIndex( openingFormationX ),
	movementYIndex( openingFormationY ),
	movementColumnIndex( openingFormationY ),
	currentMovementDirection( MovementDirections::RIGHT )
{
	for( auto enemy : enemies )
	{
		enemy = nullptr;
	}
}

EnemyManager::EnemyManager( TextureCodex& textureCodex )
	:
	openingFormationX( enemyRowLength - 1 ),
	openingFormationY( enemyColumnHeight - 1 ),
	movementXIndex( openingFormationX ),
	movementYIndex( openingFormationY ),
	movementColumnIndex( openingFormationY ),
	currentMovementDirection( MovementDirections::RIGHT )
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
	currentMovementDirection = MovementDirections::RIGHT;
	executingOpeningFormation = true;
	openingFormationX = enemyRowLength - 1;
	openingFormationY = enemyColumnHeight - 1;
	movementXIndex = openingFormationY;
	movementYIndex = openingFormationY;
	movementColumnIndex = openingFormationY;
}

void EnemyManager::UpdateEnemies()
{
	DoOpeningFormation();
	HandleEnemyMovement();
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

void EnemyManager::HandleEnemyMovement()
{
	if( !executingOpeningFormation )
	{
		MoveEnemies( GetMovementVector() );
		movementColumnIndex--;

		if( movementColumnIndex < 0 )
		{
			movementColumnIndex = enemyColumnHeight - 1;
			SetMovementDirection();
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

void EnemyManager::DoOpeningFormation()
{
	if( executingOpeningFormation )
	{
		enemies[ openingFormationY * enemyRowLength + openingFormationX ]->Revive();
		openingFormationX -= 1;

		if(openingFormationX < 0 )
		{
			openingFormationX = enemyRowLength - 1;
			openingFormationY -= 1;
		}

		if( openingFormationY < 0 )
			executingOpeningFormation = false;
	}
}

void EnemyManager::MoveEnemies( sf::Vector2< float > direction )
{
	for( int rowIndex = 0; rowIndex < enemyRowLength; rowIndex++ )
	{
		enemies[ movementColumnIndex * enemyRowLength + rowIndex ]->Move( direction );
	}
}

void EnemyManager::SetMovementDirection()
{
	if( horizontalMovementCount > 0 && verticalMovementCount == 1 )
	{
		horizontalMovementCount--;
	}
	else if( horizontalMovementCount == 0 && verticalMovementCount == 1 )
	{
		verticalMovementCount--;
		currentMovementDirection = MovementDirections::DOWN;
	}
	else if( horizontalMovementCount == 0 && verticalMovementCount == 0 )
	{
		if( isGoingLeft )
		{
			currentMovementDirection = MovementDirections::RIGHT;
			horizontalMovementCount = 11;
			verticalMovementCount = 1;
			isGoingLeft = !isGoingLeft;
		}
		else
		{
			currentMovementDirection = MovementDirections::LEFT;
			horizontalMovementCount = 11;
			verticalMovementCount = 1;
			isGoingLeft = !isGoingLeft;
		}
	}
}

sf::Vector2< float > EnemyManager::GetMovementVector()
{
	switch( currentMovementDirection )
	{
	case MovementDirections::LEFT:
		return sf::Vector2< float >( -20.0f, 0.0f );

	case MovementDirections::RIGHT:
		return sf::Vector2< float >( 20.0f, 0.0f );

	case MovementDirections::DOWN:
		return sf::Vector2< float >( 0.0f, 20.0f );

	default:
		return sf::Vector2< float >( 0.0f, 0.0f );
	}
}