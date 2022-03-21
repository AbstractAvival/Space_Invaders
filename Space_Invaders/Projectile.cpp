#include "Projectile.h"

Projectile::Projectile( TextureCodex& textureCodex, sf::Vector2f position, bool isShootingUpIn )
	:
	GameObject( position ),
	currentSprite( ProjectileStatus::Normal ),
	isShootingUp( isShootingUpIn )
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

bool Projectile::IsShootingUp()
{
	return isShootingUp;
}

void Projectile::InitializeSprites( TextureCodex& textureCodex )
{
}
