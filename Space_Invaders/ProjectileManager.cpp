#include "ProjectileManager.h"

ProjectileManager::ProjectileManager( TextureCodex& textureCodexIn )
	:
	textureCodex( &textureCodexIn )
{}

void ProjectileManager::UpdateProjectiles( float frameTime )
{
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
}

void ProjectileManager::ShootPlayerProjectile( sf::Vector2f position )
{
}

void ProjectileManager::HandlePlayerProjectiles()
{
	for( auto currentProjectile = playerProjectiles.begin(); currentProjectile != playerProjectiles.end(); )
	{
		if( ( *currentProjectile )->GetPosition().y <= 200.0f )
		{
			( *currentProjectile )->ChangeStatus( Projectile::ProjectileStatus::Heated );
		}

		if( ( *currentProjectile )->GetPosition().y <= 75.0f )
		{
			( *currentProjectile )->Explode();
		}
	}
}
