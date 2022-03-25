#include "ProjectileManager.h"

ProjectileManager::ProjectileManager( TextureCodex& textureCodexIn, EnemyManager& enemyManagerIn )
	:
	textureCodex( &textureCodexIn ),
	enemyManager( &enemyManagerIn )
{}

ProjectileManager::~ProjectileManager()
{
	for( auto projectile : playerProjectiles )
	{
		delete projectile;
		projectile = nullptr;
	}

	for( auto projectile : enemyProjectiles )
	{
		delete projectile;
		projectile = nullptr;
	}
}

void ProjectileManager::UpdateProjectiles( float frameTime )
{
	if( !enemyManager->IsExecutingOpeningFormation() )
	{
		enemyProjectileCooldown -= frameTime;
		HandlePlayerProjectiles();
		HandleEnemyProjectiles();
		ShootEnemyProjectile();
	}

	for( auto playerProjectile : playerProjectiles )
	{
		playerProjectile->Update( frameTime );
	}

	for( auto enemyProjectile : enemyProjectiles )
	{
		enemyProjectile->Update( frameTime );
	}
}

void ProjectileManager::RenderProjectiles( sf::RenderWindow& window, float interpolation )
{
	for( auto playerProjectile : playerProjectiles )
	{
		playerProjectile->Render( window, interpolation );
	}

	for( auto enemyProjectile : enemyProjectiles )
	{
		enemyProjectile->Render( window, interpolation );
	}
}

void ProjectileManager::ShootPlayerProjectile( sf::Vector2f position )
{
	if( playerProjectiles.size() < 1 )
	{
		playerProjectiles.emplace_back( new Projectile( *textureCodex, position, true ) );
	}
}

void ProjectileManager::ShootEnemyProjectile()
{
	if( enemyProjectileCooldown <= 0.0f )
	{
		Enemy enemy = enemyManager->GetRandomFrontlineEnemy();
		if( !enemy.IsDead() )
		{
			enemyProjectiles.emplace_back( new Projectile( *textureCodex, enemy.GetPosition(), false ) );
			enemyProjectileCooldown = maxEnemyProjectileCooldown;
		}
	}
}

void ProjectileManager::HandlePlayerProjectiles()
{
	for( auto currentProjectile = playerProjectiles.begin(); currentProjectile != playerProjectiles.end(); )
	{
		if( ( *currentProjectile )->GetPosition().y <= 150.0f )
		{
			( *currentProjectile )->ChangeStatus( Projectile::ProjectileStatus::Heated );
		}

		if( ( *currentProjectile )->GetPosition().y <= 75.0f )
		{
			( *currentProjectile )->Explode();
		}

		if( ( *currentProjectile )->IsDead() )
		{
			delete ( *currentProjectile );
			currentProjectile = playerProjectiles.erase( currentProjectile );
		}
		else
		{
			++currentProjectile;
		}
	}
}

void ProjectileManager::HandleEnemyProjectiles()
{
	for( auto currentProjectile = enemyProjectiles.begin(); currentProjectile != enemyProjectiles.end(); )
	{
		if( ( *currentProjectile )->GetPosition().y >= 475.0f )
		{
			( *currentProjectile )->ChangeStatus( Projectile::ProjectileStatus::Heated );
		}

		if( ( *currentProjectile )->GetPosition().y >= 575.0f )
		{
			( *currentProjectile )->Explode();
		}

		if( ( *currentProjectile )->IsDead() )
		{
			delete ( *currentProjectile );
			currentProjectile = enemyProjectiles.erase( currentProjectile );
		}
		else
		{
			++currentProjectile;
		}
	}
}