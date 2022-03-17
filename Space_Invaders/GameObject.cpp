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

sf::FloatRect GameObject::GetBoundary()
{
	return sprites[ int( currentSprite ) ].getGlobalBounds();
}

float GameObject::GetTextureWidth()
{
	if( !sprites.empty() )
	{
		return float( sprites[ int( currentSprite ) ].getTexture()->getSize().x );
	}
	return 0.0f;
}

float GameObject::GetTextureHeight()
{
	if( !sprites.empty() )
	{
		return float( sprites[ int( currentSprite ) ].getTexture()->getSize().y );
	}
	return 0.0f;
}

void GameObject::SetPosition( sf::Vector2< float > newPosition )
{
	if( !sprites.empty() )
	{
		for( int spriteIndex = 0; spriteIndex < int( sprites.size() ); spriteIndex++ )
		{
			sf::Vector2< float > offsetPosition( newPosition.x - ( sprites[ spriteIndex ].getTexture()->getSize().x / 2 ), newPosition.y - ( sprites[ spriteIndex ].getTexture()->getSize().y  / 2 ) );
			sprites[ spriteIndex ].setPosition( offsetPosition );
		}
	}
	position = newPosition;
}

void GameObject::Move( sf::Vector2< float > offset )
{
	SetPosition( GetPosition() + offset );
}

void GameObject::Kill()
{
	isDead = true;
}

void GameObject::Revive()
{
	isDead = false;
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