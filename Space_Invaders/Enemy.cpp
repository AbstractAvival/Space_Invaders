#include "Enemy.h"

Enemy::Enemy()
	:
	GameObject( sf::Vector2< float >( 0, 0 ) ),
	enemyType( EnemyTypes::TestEnemy )
{
	currentSprite = Sprites::Contract;
}

Enemy::Enemy( TextureCodex& codex, EnemyTypes enemyTypeIn, sf::Vector2< float > positionIn )
	:
	GameObject( positionIn ),
	enemyType( enemyTypeIn )
{
	currentSprite = Sprites::Contract;
	InitializeSprites( codex );
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
}

void Enemy::Render( sf::RenderWindow& window, float interpolation )
{
	if( !IsDead() )
	{
		window.draw( sprites[ ( int )currentSprite ] );
	}
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
	sprites.emplace_back( sf::Sprite() );
	sprites[ ( int )currentSprite ].setTexture( textureCodex.GetGameTexture( GameTextureTypes::WhiteBox ) );
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

void Enemy::LoadSprites( TextureCodex& textureCodex, GameTextureTypes types[ 3 ] )
{
	for( int spriteIndex = 0; spriteIndex < 3; spriteIndex++ )
	{
		sprites.emplace_back( sf::Sprite() );
		sprites[ spriteIndex ].setTexture( textureCodex.GetGameTexture( types[ spriteIndex ] ) );
	}
}