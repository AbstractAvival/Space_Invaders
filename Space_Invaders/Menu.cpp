#include "Menu.h"

Menu::Menu( TextureCodex& textureCodex, std::vector< std::string > items, float screenWidth, float screenHeight )
	:
	Menu(textureCodex, items, screenWidth, screenHeight, 0, 0)
{}

Menu::Menu( TextureCodex& textureCodex, std::vector< std::string > items, float screenWidth, float screenHeight, float xDisplacement, float yDisplacement )
{
	InitializeMenuItems(textureCodex, items);
	SetMenuItemPositions(screenWidth, screenHeight, xDisplacement, yDisplacement);
	SetItemSelectorPosition();
}

void Menu::HandleInput()
{
	if( accumulatedFrameTime >= maxInputCooldown && sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
	{
		if( currentItem <= 0 )
		{
			currentItem = int( items.size() - 1 );
		}
		else
		{
			currentItem--;
		}
		accumulatedFrameTime = 0.0f;
		SetItemSelectorPosition();
	}

	if( accumulatedFrameTime >= maxInputCooldown && sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
	{
		if( currentItem >= int( items.size() - 1 ) )
		{
			currentItem = 0;
		}
		else
		{
			currentItem++;
		}
		accumulatedFrameTime = 0.0f;
		SetItemSelectorPosition();
	}
}

void Menu::Update( float frameTime )
{
	if( accumulatedFrameTime < maxInputCooldown )
	{
		accumulatedFrameTime += frameTime;
	}
}

void Menu::Render( sf::RenderWindow& window, float interpolation )
{
	for( auto& item : items )
	{
		window.draw( item );
	}
	window.draw( selector );
}

void Menu::ResetOptions()
{
	currentItem = 0;
	SetItemSelectorPosition();
}

int Menu::getCurrentMenuItem()
{
	return currentItem;
}

void Menu::InitializeMenuItems( TextureCodex& textureCodex, std::vector< std::string > desiredItems )
{
	selector.setTexture( textureCodex.GetMenuTexture( MenuTextureTypes::Selector ) );
	for( auto item : desiredItems )
	{
		items.emplace_back( sf::Text() );
		items[ int( items.size() ) - 1 ].setFont( textureCodex.GetFont() );
		items[ int( items.size() ) - 1 ].setCharacterSize( 25 );
		items[ int( items.size() ) - 1 ].setString( item );
	}
}

void Menu::SetMenuItemPositions( float screenWidth, float screenHeight, float xDisplacement, float yDisplacement )
{
	float startingHeight = ( screenHeight / 2 ) - ( items.size() * ( estimatedCharacterHeight + verticalSeparationDistance ) / 2 );
	for( int index = 0; index < int( items.size() ); index++ )
	{
		float xPosition = ( screenWidth / 2 - float( items[ index ].getCharacterSize() / 2 ) ) + xDisplacement;
		float yPosition = startingHeight + ( estimatedCharacterHeight + verticalSeparationDistance ) * index;
		items[ index ].setPosition( { xPosition, yPosition } );
	}
}

void Menu::SetItemSelectorPosition()
{
	float yPosition = items[ currentItem ].getPosition().y + ( estimatedCharacterHeight / 2 ) - ( selector.getGlobalBounds().height / 2 );
	float xPosition = items[ currentItem ].getPosition().x - ( selector.getGlobalBounds().width + horizontalSeparationDistance );
	selector.setPosition( xPosition, yPosition );
}