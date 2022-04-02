#include "PlayerShip.h"

PlayerShip::PlayerShip(TextureCodex& textureCodex, sf::Vector2< float > positionIn)
	:
	GameObject(positionIn)
{
	GameTextureTypes shipTextures[ 3 ] = { GameTextureTypes::PlayerShip, GameTextureTypes::PlayerShipExplosionA, GameTextureTypes::PlayerShipExplosionB };
	LoadSprites( textureCodex, shipTextures );
	SetPosition( positionIn );
}

void PlayerShip::Update( float frameTime )
{
}

void PlayerShip::Render( sf::RenderWindow& window, float interpolation )
{
	window.draw( sprites[ int( currentSprite ) ] );
}

void PlayerShip::SetCurrentSprite(Sprites newSprite)
{
	currentSprite = newSprite;
}

void PlayerShip::Revive()
{
	GameObject::Revive();
	currentSprite = Sprites::Contract;
}

Sprites PlayerShip::GetCurrentSprite()
{
	return currentSprite;
}
