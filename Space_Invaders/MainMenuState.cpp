#include "MainMenuState.h"

MainMenuState::MainMenuState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, int screenWidthIn, int screenHeightIn )
	:
	GameState( windowIn, handlerIn, screenWidthIn, screenHeightIn ),
	mainMenu( textureCodex, desiredItems, float( screenWidthIn ), float( screenHeightIn ) )
{}

void MainMenuState::InitializeState()
{
}

void MainMenuState::ResetState()
{
}

void MainMenuState::Enter()
{
}

void MainMenuState::HandleInput()
{
}

void MainMenuState::UpdateLogic( float frameTime )
{
}

void MainMenuState::Render( float interpolation )
{
	mainMenu.Render( *window, interpolation );
}