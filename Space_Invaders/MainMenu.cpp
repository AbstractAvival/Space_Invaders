#include "MainMenu.h"
#include "StateHandler.h"

MainMenu::MainMenu( TextureCodex& textureCodex, std::vector< std::string > items, float screenWidth, float screenHeight )
	:
	Menu( textureCodex, items, screenWidth, screenHeight, 0, 0 )
{}

MainMenu::MainMenu( TextureCodex& textureCodex, std::vector< std::string > items, float screenWidth, float screenHeight, float xDisplacement, float yDisplacement )
{
	InitializeMenuItems( textureCodex, items );
	SetMenuItemPositions( screenWidth, screenHeight, xDisplacement, yDisplacement );
	SetItemSelectorPosition();
}

MainMenu::~MainMenu()
{
}

void MainMenu::HandleInput( class StateHandler& handler, AudioManager& audioManager )
{
	Menu::HandleInput( audioManager );
	if( accumulatedFrameTime >= maxInputCooldown && sf::Keyboard::isKeyPressed( sf::Keyboard::Enter ) )
	{
		handler.ChangeState( GetDesiredState() );
	}
}

StateTypes MainMenu::GetDesiredState()
{
	switch( currentItem )
	{
	case 0:
		return StateTypes::PLAYSTATE;

	case 1:
		return StateTypes::SETTINGSSTATE;
		
	default:
		return StateTypes::MAINMENUSTATE;
	}
}