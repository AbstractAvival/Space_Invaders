#include "Enemy.h"

Enemy::Enemy()
	:
	GameObject( sf::Vector2< int >( 0, 0 ) )
{
}

Enemy::Enemy( TextureCodex& codex, EnemyTypes enemyType, sf::Vector2< int > positionIn )
	:
	GameObject( positionIn )
{
	currentSprite = Sprites::Contract;
	LoadSprites( codex, enemyType );
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

void Enemy::LoadSprites( TextureCodex& textureCodex, EnemyTypes enemyType )
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
}

void Enemy::LoadTierTwoSprites( TextureCodex& textureCodex )
{
}

void Enemy::LoadTierThreeSprites( TextureCodex& textureCodex )
{
}
