#include "Projectile.h"

Projectile::Projectile( TextureCodex& textureCodex, sf::Vector2f position )
	:
	GameObject( position ),
	currentSprite( ProjectileStatus::Normal )
{
	InitializeSprites( textureCodex );
}

void Projectile::Update()
{
}

void Projectile::Render( sf::RenderWindow& window, float interpolation )
{
	window.draw( sprites[ int( currentSprite ) ] );
}

void Projectile::InitializeSprites( TextureCodex& textureCodex )
{
}
