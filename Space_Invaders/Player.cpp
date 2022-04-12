#include "Player.h"

Player::Player( TextureCodex& textureCodex, sf::Vector2< float > positionIn )
	:
	GameObject( positionIn )
{
	GameTextureTypes shipTextures[ 3 ] = { GameTextureTypes::PlayerShip, GameTextureTypes::PlayerShipExplosionA, GameTextureTypes::PlayerShipExplosionB };
	LoadSprites( textureCodex, shipTextures );
	SetPosition( positionIn );
}

void Player::Update( float frameTime )
{
}

void Player::Render( sf::RenderWindow& window, float interpolation )
{
	window.draw( sprites[ int( currentSprite ) ] );
}

void Player::SetCurrentSprite(Sprites newSprite)
{
	currentSprite = newSprite;
}

void Player::Revive()
{
	GameObject::Revive();
	currentSprite = Sprites::Contract;
}

Sprites Player::GetCurrentSprite()
{
	return currentSprite;
}
