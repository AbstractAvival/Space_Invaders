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

void Menu::HandleInput()
{
}

void Menu::Render( sf::RenderWindow& window, float interpolation )
{
	for( auto item : items )
	{
		window.draw( *item );
	}
}

void Menu::ResetOptions()
{
}

int Menu::getCurrentOption()
{
	return currentOption;
}

void Menu::InitializeMenuItems( TextureCodex& textureCodex, vector< StateTypes > desiredItems )
{
	for( auto item : desiredItems )
	{
		items.emplace_back( sf::Text() );
		items[ int( items.size() ) - 1 ]->setFont( textureCodex.GetFont() );
		items[ int( items.size() ) - 1 ]->setString( GetMenuItemText( item ) );
	}
}

void Menu::SetMenuItemPositions( float screenWidth, float screenHeight, float xDisplacement, float yDisplacement )
{
}

void Menu::SetItemSelectorPosition()
{
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