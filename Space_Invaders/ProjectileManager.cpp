#include "ProjectileManager.h"

ProjectileManager::ProjectileManager( TextureCodex& textureCodexIn )
	:
	textureCodex( &textureCodexIn )
{}

void ProjectileManager::UpdateProjectiles()
{
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
