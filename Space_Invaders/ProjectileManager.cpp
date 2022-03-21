#include "ProjectileManager.h"

ProjectileManager::ProjectileManager( TextureCodex& textureCodexIn )
	:
	textureCodex( &textureCodexIn )
{}

void ProjectileManager::UpdateProjectiles()
{
	for( auto playerProjectile : playerProjectiles )
	{
		if( !playerProjectile->IsDead() )
		{
			playerProjectile->Move( sf::Vector2f( 0.0f, -playerProjectileSpeed ) );
		}
	}

	for( auto enemyProjectile : enemyProjectiles )
	{
		if( !enemyProjectile->IsDead() )
		{
			enemyProjectile->Move( sf::Vector2f( 0.0f, enemyProjectileSpeed ) );
		}
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
	{}
}
