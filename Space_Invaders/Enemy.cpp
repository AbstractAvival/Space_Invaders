#include "Enemy.h"

Enemy::Enemy()
	:
	GameObject( sf::Vector2< int >( 0, 0 ) )
{
}

Enemy::Enemy( TextureCodex& codex, sf::Vector2< int > positionIn )
	:
	GameObject( positionIn )
{
	currentSprite = Sprites::Contract;
	LoadSprites( codex );
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

void Enemy::LoadSprites( TextureCodex& codex )
{
	sprites.emplace_back( sf::Sprite() );
	sprites[ ( int )currentSprite ].setTexture( codex.GetGameTexture( GameTextureTypes::WhiteBox ) );
}
