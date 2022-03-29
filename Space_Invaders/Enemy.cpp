#include "Enemy.h"

Enemy::Enemy()
	:
	GameObject( sf::Vector2f( 0, 0 ) ),
	enemyType( EnemyTypes::TestEnemy )
{
	currentSprite = Sprites::Contract;
}

Enemy::Enemy( TextureCodex& codex, EnemyTypes enemyTypeIn, sf::Vector2f positionIn )
	:
	GameObject( positionIn ),
	enemyType( enemyTypeIn )
{
	currentSprite = Sprites::Contract;
	InitializeSprites( codex );
	SetPosition( positionIn );
}

Enemy::Enemy( const Enemy& enemy )
	:
	GameObject( enemy.position ),
	enemyType( enemy.enemyType )
{
	isDead = enemy.isDead;
	currentSprite = enemy.currentSprite;
	for( int spriteIndex = 0; spriteIndex < int( enemy.sprites.size() ); spriteIndex++ )
	{
		sprites.emplace_back( sf::Sprite() );
		sprites[ spriteIndex ].setTexture( *enemy.sprites[ spriteIndex ].getTexture() );
	}
	SetPosition( enemy.position );
}

Enemy::~Enemy()
{
}

void Enemy::Update( float frameTime )
{
}

void Enemy::Render( sf::RenderWindow& window, float interpolation )
{
	if( !IsDead() )
	{
		window.draw( sprites[ int( currentSprite ) ] );
	}
}

void Enemy::Move( sf::Vector2f offset )
{
	if( enemyType != EnemyTypes::Boss )
		SwapMovementSprite();

	GameObject::Move( offset );
}

void Enemy::SetSprite( int spriteIndex )
{
	currentSprite = Sprites( spriteIndex );
}

int Enemy::GetCurrentSprite()
{
	return int( currentSprite );
}

EnemyTypes Enemy::GetEnemyType()
{
	return enemyType;
}

void Enemy::InitializeSprites( TextureCodex& textureCodex )
{
	switch( enemyType )
	{
	case EnemyTypes::Boss:
		LoadBossSprite( textureCodex );
		break;

	case EnemyTypes::TierOne:
		LoadTierOneSprites( textureCodex );
		break;

	case EnemyTypes::TierTwo:
		LoadTierTwoSprites( textureCodex );
		break;

	case EnemyTypes::TierThree:
		LoadTierThreeSprites( textureCodex );
		break;

	case EnemyTypes::TestEnemy:
		LoadTestSprite( textureCodex );
		break;
	}
}

void Enemy::LoadBossSprite( TextureCodex& textureCodex )
{
	GameTextureTypes spriteTypes[ 3 ] = { GameTextureTypes::WhiteBox, GameTextureTypes::WhiteBox, GameTextureTypes::Explosion };
	LoadSprites( textureCodex, spriteTypes );
}

void Enemy::LoadTierOneSprites( TextureCodex& textureCodex )
{
	GameTextureTypes spriteTypes[ 3 ] = { GameTextureTypes::EnemyOneFirst, GameTextureTypes::EnemyOneSecond, GameTextureTypes::Explosion };
	LoadSprites( textureCodex, spriteTypes );
}

void Enemy::LoadTierTwoSprites( TextureCodex& textureCodex )
{
	GameTextureTypes spriteTypes[ 3 ] = { GameTextureTypes::EnemyTwoFirst, GameTextureTypes::EnemyTwoSecond, GameTextureTypes::Explosion };
	LoadSprites( textureCodex, spriteTypes );
}

void Enemy::LoadTierThreeSprites( TextureCodex& textureCodex )
{
	GameTextureTypes spriteTypes[ 3 ] = { GameTextureTypes::EnemyThirdFirst, GameTextureTypes::EnemyThirdSecond, GameTextureTypes::Explosion };
	LoadSprites( textureCodex, spriteTypes );
}

void Enemy::SwapMovementSprite()
{
	if( currentSprite == Sprites::Contract )
	{
		currentSprite = Sprites::Expand;
	}
	else if( currentSprite == Sprites::Expand )
	{
		currentSprite = Sprites::Contract;
	}
}