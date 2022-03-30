#include "Menu.h"

Menu::Menu()
{
}

Menu::Menu( StateTypes items[], float screenWidth, float screenHeight )
{
	Menu( items, screenWidth, screenHeight, 0, 0 );
}

Menu::Menu( StateTypes items[], float screenWidth, float screenHeight, float xDisplacement, float yDisplacement )
{
	InitializeMenuItems( items );
	SetMenuItemPositions( screenWidth, screenHeight, xDisplacement, yDisplacement );
	SetItemSelectorPosition();
}

void Menu::HandleInput()
{
}

void Menu::Render( sf::RenderWindow& window, float interpolation )
{
}

void Menu::ResetOptions()
{
}

int Menu::getCurrentOption()
{
	return currentOption;
}

void Menu::InitializeMenuItems( StateTypes items[] )
{
}

void Menu::SetMenuItemPositions( float screenWidth, float screenHeight, float xDisplacement, float yDisplacement )
{
}

void Menu::SetItemSelectorPosition()
{
}
