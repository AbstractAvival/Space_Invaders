#include "ProjectileManager.h"
#include "PlayerManager.h"

ProjectileManager::ProjectileManager( TextureCodex& textureCodexIn, AudioManager& audioManagerIn, EnemyManager& enemyManagerIn, class PlayerManager& playerManagerIn )
	:
	textureCodex( &textureCodexIn ),
	audioManager( &audioManagerIn ),
	enemyManager( &enemyManagerIn ),
	playerManager( &playerManagerIn )
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

void ProjectileManager::UpdateProjectiles( float frameTime, bool playerExploded )
{
	if( !enemyManager->IsExecutingOpeningFormation() )
	{
		enemyProjectileCooldown -= frameTime;
		HandlePlayerProjectiles();
		HandlePlayerShotCollision();
		HandleEnemyProjectiles();
		HandleEnemyShotCollision();

		if( !playerExploded )
		{
			ShootEnemyProjectile();
		}

		if( playerExploded )
		{
			ClearAllEnemyProjectiles();
		}
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
		audioManager->PlaySound( AudioTypes::PlayerShot );
	}
}

void ProjectileManager::ResetProjectiles()
{
	enemyProjectileCooldown = maxEnemyProjectileCooldown;
	for( auto currentProjectile = enemyProjectiles.begin(); currentProjectile != enemyProjectiles.end(); )
	{
		delete ( *currentProjectile );
		currentProjectile = enemyProjectiles.erase( currentProjectile );
	}

	for( auto currentProjectile = playerProjectiles.begin(); currentProjectile != playerProjectiles.end(); )
	{
		delete ( *currentProjectile );
		currentProjectile = playerProjectiles.erase( currentProjectile );
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
			audioManager->PlaySound( AudioTypes::EnemyShot );
		}
	}
}

void ProjectileManager::ClearAllEnemyProjectiles()
{
	enemyProjectileCooldown = maxEnemyProjectileCooldown;
	for( auto currentProjectile = enemyProjectiles.begin(); currentProjectile != enemyProjectiles.end(); )
	{
		delete ( *currentProjectile );
		currentProjectile = enemyProjectiles.erase( currentProjectile );
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

void ProjectileManager::HandlePlayerShotCollision()
{
	if( !playerProjectiles.empty() && enemyManager->CheckCollisionAndKill( playerProjectiles[ 0 ]->GetBoundary() ) )
	{
		delete playerProjectiles[ 0 ];
		playerProjectiles.clear();
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

		if( ( *currentProjectile )->GetPosition().y >= 550.0f )
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

void ProjectileManager::HandleEnemyShotCollision()
{
	if( !enemyProjectiles.empty() )
	{
		for( auto currentProjectile = enemyProjectiles.begin(); currentProjectile != enemyProjectiles.end(); )
		{
			if( playerManager->CheckCollisionAndKill( ( *currentProjectile )->GetBoundary() ) )
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
}