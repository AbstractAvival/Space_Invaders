#include "Projectile.h"

Projectile::Projectile( TextureCodex& textureCodex, sf::Vector2f position, bool isPlayerProjectile )
	:
	GameObject( position ),
	projectileStatus( ProjectileStatus::Normal ),
	isDoingEndingAnimation( false ),
	remainingTime( 0.5f )
{
	InitializeSprites( textureCodex, isPlayerProjectile );
}

void Projectile::Update( float frameTime )
{
	DoExplodingAnimation( frameTime );
}

void Projectile::Render( sf::RenderWindow& window, float interpolation )
{
	window.draw( sprites[ int( currentSprite ) ] );
}

sf::FloatRect Projectile::GetBoundary()
{
	return sprites[ int( projectileStatus ) ].getGlobalBounds();
}

float Projectile::GetTextureWidth()
{
	if( !sprites.empty() )
	{
		return float( sprites[ int( projectileStatus ) ].getTexture()->getSize().x );
	}
	return 0.0f;
}

float Projectile::GetTextureHeight()
{
	if( !sprites.empty() )
	{
		return float( sprites[ int( projectileStatus ) ].getTexture()->getSize().y );
	}
	return 0.0f;
}

void Projectile::Explode()
{
	projectileStatus = ProjectileStatus::Exploded;
	isDoingEndingAnimation = true;
}

void Projectile::InitializeSprites( TextureCodex& textureCodex, bool isPlayerProjectile )
{
	if( isPlayerProjectile )
	{
		InitializePlayerSprites( textureCodex );
	}
	else
	{
		InitializeEnemySprites( textureCodex );
	}
}

void Projectile::InitializePlayerSprites( TextureCodex& textureCodex )
{
	GameTextureTypes spriteTypes[ 3 ] = { GameTextureTypes::PlayerProjectileNormal, GameTextureTypes::PlayerProyectileHeated, GameTextureTypes::PlayerProjectileExploded };
	LoadSprites( textureCodex, spriteTypes );
}

void Projectile::InitializeEnemySprites( TextureCodex& textureCodex )
{
	GameTextureTypes spriteTypes[ 3 ] = { GameTextureTypes::EnemyProjectileNormal, GameTextureTypes::EnemyProjectileHeated, GameTextureTypes::EnemyProjectileExploded };
	LoadSprites( textureCodex, spriteTypes );
}

void Projectile::DoExplodingAnimation( float frameTime )
{
	if( isDoingEndingAnimation && remainingTime > 0.0f )
	{
		remainingTime -= frameTime;
	}

	if( isDoingEndingAnimation && remainingTime <= 0.0f )
	{
		Kill();
	}
}