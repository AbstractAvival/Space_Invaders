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

EnemyManager::EnemyManager( TextureCodex& textureCodex, HeadsUpDisplay& hudDisplayIn )
	:
	hudDisplay( &hudDisplayIn ),
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
	isExecutingOpeningFormation = true;
	openingFormationX = enemyRowLength - 1;
	openingFormationY = enemyColumnHeight - 1;
	movementXIndex = openingFormationY;
	movementYIndex = openingFormationY;
	movementColumnIndex = openingFormationY;
}

void EnemyManager::UpdateEnemies( float frameTime )
{
	accumulatedFrameTime += frameTime;
	DoOpeningFormation();
	HandleEnemyMovement( frameTime );
	ClearExplodedEnemies();
}

void EnemyManager::RenderEnemies( sf::RenderWindow& window, float interpolation )
{
	for( auto enemy : enemies )
	{
		if( !enemy->IsDead() )
		{
			enemy->Render( window, interpolation );
		}
	}
}

bool EnemyManager::CheckCollisionAndKill( sf::FloatRect playerShotBoundary )
{
	bool collided = false;
	for( auto enemy : enemies )
	{
		if( !enemy->IsDead() && playerShotBoundary.intersects( enemy->GetBoundary() ) )
		{
			enemy->SetSprite( explodedValue );
			hudDisplay->ModifyScore( enemy->GetEnemyType() );
			collided = true;
		}
	}
	return collided;
}

bool EnemyManager::IsExecutingOpeningFormation()
{
	return isExecutingOpeningFormation;
}

Enemy EnemyManager::GetRandomFrontlineEnemy()
{
	int xIndex = numberGenerator.GetRandomInt( 0, 10 );
	Enemy placeholder = *enemies[ 0 + xIndex ];
	for( int column = 0; column < 5; column++ )
	{
		if( !enemies[ column * enemyRowLength + xIndex ]->IsDead() )
		{
			placeholder = *enemies[ column * enemyRowLength + xIndex ];
		}
	}
	return placeholder;
}

void EnemyManager::CreateTierOneEnemies( TextureCodex& textureCodex )
{
	CreateEnemies( textureCodex, EnemyTypes::TierOne, 3, 5 );
}

void EnemyManager::CreateTierTwoEnemies( TextureCodex& textureCodex )
{
	CreateEnemies( textureCodex, EnemyTypes::TierTwo, 1, 3 );
}

void EnemyManager::CreateTierThreeEnemies( TextureCodex& textureCodex )
{
	CreateEnemies( textureCodex, EnemyTypes::TierThree, 0, 1 );
}

void EnemyManager::CreateBoss( TextureCodex& textureCodex )
{
	sf::Vector2f enemyPosition = sf::Vector2f( -50.0f, -50.0f );
	boss = new Enemy( textureCodex, EnemyTypes::Boss, enemyPosition );
}

void EnemyManager::CreateEnemies( TextureCodex& textureCodex, EnemyTypes desiredEnemyType, int startingColumn, int endingColumn )
{
	for( int columnIndex = startingColumn; columnIndex < endingColumn; columnIndex++ )
	{
		for( int rowIndex = 0; rowIndex < enemyRowLength; rowIndex++ )
		{
			sf::Vector2f enemyPosition = sf::Vector2f( ( rowIndex * horizontalSeparationDistance ) + startingXPosition, ( columnIndex * verticalSeparationDistance ) + startingYPosition );
			enemies[ columnIndex * enemyRowLength + rowIndex ] = new Enemy( textureCodex, desiredEnemyType, enemyPosition );
			enemies[ columnIndex * enemyRowLength + rowIndex ]->Kill();
		}
	}
}

void EnemyManager::HandleEnemyMovement( float frameTime )
{
	if( !isExecutingOpeningFormation && accumulatedFrameTime > maxFrameTime )
	{
		accumulatedFrameTime = 0.0f;
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
			sf::Vector2f enemyPosition = sf::Vector2f( ( rowIndex * horizontalSeparationDistance ) + startingXPosition, ( columnIndex * verticalSeparationDistance ) + startingYPosition );
			enemies[ columnIndex * enemyRowLength + rowIndex ]->SetPosition( enemyPosition );
		}
	}
}

void EnemyManager::DoOpeningFormation()
{
	if( isExecutingOpeningFormation )
	{
		enemies[ openingFormationY * enemyRowLength + openingFormationX ]->Revive();
		openingFormationX -= 1;

		if(openingFormationX < 0 )
		{
			openingFormationX = enemyRowLength - 1;
			openingFormationY -= 1;
		}

		if( openingFormationY < 0 )
			isExecutingOpeningFormation = false;
	}
}

void EnemyManager::MoveEnemies( sf::Vector2f direction )
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
		maxFrameTime -= 0.02f;
		if( isGoingLeft )
		{
			currentMovementDirection = MovementDirections::RIGHT;
		}
		else
		{
			currentMovementDirection = MovementDirections::LEFT;
		}

		horizontalMovementCount = 14;
		verticalMovementCount = 1;
		isGoingLeft = !isGoingLeft;
	}
}

void EnemyManager::ClearExplodedEnemies()
{
	for( auto enemy : enemies )
	{
		if( enemy->GetCurrentSprite() == explodedValue )
			enemy->Kill();
	}
}

sf::Vector2f EnemyManager::GetMovementVector()
{
	switch( currentMovementDirection )
	{
	case MovementDirections::LEFT:
		return sf::Vector2f( -20.0f, 0.0f );

	case MovementDirections::RIGHT:
		return sf::Vector2f( 20.0f, 0.0f );

	case MovementDirections::DOWN:
		return sf::Vector2f( 0.0f, 20.0f );

	default:
		return sf::Vector2f( 0.0f, 0.0f );
	}
}