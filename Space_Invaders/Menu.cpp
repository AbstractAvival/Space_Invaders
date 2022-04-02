#include "Menu.h"

Menu::Menu()
{
}

Menu::Menu( TextureCodex& textureCodex, vector< StateTypes > items, float screenWidth, float screenHeight )
	:
	Menu( textureCodex, items, screenWidth, screenHeight, 0, 0 )
{}

Menu::Menu( TextureCodex& textureCodex, vector< StateTypes > items, float screenWidth, float screenHeight, float xDisplacement, float yDisplacement )
{
	InitializeMenuItems( textureCodex, items );
	SetMenuItemPositions( screenWidth, screenHeight, xDisplacement, yDisplacement );
	SetItemSelectorPosition();
}

Menu::~Menu()
{
}

void Menu::HandleInput()
{
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

void Menu::InitializeMenuItems( TextureCodex& textureCodex, vector< StateTypes > desiredItems )
{
	selector.setTexture( textureCodex.GetMenuTexture( MenuTextureTypes::Selector ) );
	for( auto item : desiredItems )
	{
		items.emplace_back( sf::Text() );
		items[ int( items.size() ) - 1 ].setFont( textureCodex.GetFont() );
		items[ int( items.size() ) - 1 ].setCharacterSize( 25 );
		items[ int( items.size() ) - 1 ].setString( GetMenuItemText( item ) );
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

string Menu::GetMenuItemText( StateTypes state )
{
	switch( state )
	{
	case StateTypes::MAINMENUSTATE:
		return "Quit";

	case StateTypes::PAUSESTATE:
		return "Pause";

	case StateTypes::PLAYSTATE:
		return "Play";

	case StateTypes::SETTINGSSTATE:
		return "Settings";

	default:
		return "";
	}
}