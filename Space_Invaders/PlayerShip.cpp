#include "PlayerShip.h"

PlayerShip::PlayerShip( TextureCodex& textureCodex, sf::Vector2< float > positionIn )
	:
	GameObject( positionIn )
{
	sprites.emplace_back( sf::Sprite() );
	sprites[ int( currentSprite ) ].setTexture( textureCodex.GetGameTexture( GameTextureTypes::PlayerShip ) );
}

void PlayerShip::Update()
{
}

void PlayerShip::Render( sf::RenderWindow& window, float interpolation )
{
	window.draw( sprites[ int( currentSprite ) ] );
}