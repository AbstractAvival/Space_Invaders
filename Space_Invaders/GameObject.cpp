#include "GameObject.h"

GameObject::GameObject( sf::Vector2< float > positionIn )
	:
	isDead( false )
{
	currentSprite = Sprites::Contract;
	SetPosition( positionIn );
}

sf::Vector2< float > GameObject::GetPosition()
{
	return position;
}

void GameObject::SetPosition( sf::Vector2< float > newPosition )
{
	if( sprites.size() != 0 )
	{
		sprites[ int( currentSprite ) ].setPosition( newPosition );
	}
	position = newPosition;
}

void GameObject::Kill()
{
	isDead = true;
}

bool GameObject::IsDead()
{
	return isDead;
}

void GameObject::LoadTestSprite( TextureCodex& textureCodex )
{
	sprites.emplace_back( sf::Sprite() );
	sprites[ int( currentSprite ) ].setTexture( textureCodex.GetGameTexture( GameTextureTypes::WhiteBox ) );
}