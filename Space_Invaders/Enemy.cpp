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

void Enemy::LoadSprites( TextureCodex& codex, EnemyTypes enemyType )
{
}

void Enemy::LoadBossSprite( TextureCodex& codex )
{
}

void Enemy::LoadTierOneSprites( TextureCodex& codex )
{
}

void Enemy::LoadTierTwoSprites( TextureCodex& codex )
{
}

void Enemy::LoadTierThreeSprites( TextureCodex& codex )
{
}
