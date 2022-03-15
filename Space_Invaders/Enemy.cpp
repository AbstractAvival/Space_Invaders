#include "Enemy.h"

Enemy::Enemy( TextureCodex& codex, sf::Vector2< int > positionIn )
	:
	GameObject( positionIn )
{
	currentSprite = Sprites::Contract;
	LoadSprites( codex );
}

Enemy::~Enemy()
{
	for( auto sprite : sprites )
	{
		delete sprite;
		sprite = nullptr;
	}
}

void Enemy::Update()
{
}

void Enemy::Render( sf::RenderWindow& window, float interpolation )
{
	if( !IsDead() )
	{
		window.draw( *sprites[ ( int )currentSprite ] );
	}
}

void Enemy::LoadSprites( TextureCodex& codex )
{
	sprites.emplace_back( new sf::Sprite() );
	sprites[ ( int )currentSprite ]->setTexture( codex.GetGameTexture( GameTextureTypes::WhiteBox ) );
}
