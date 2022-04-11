#include "MainMenuState.h"

MainMenuState::MainMenuState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, AudioManager& audioManagerIn, int screenWidthIn, int screenHeightIn )
	:
	GameState( windowIn, handlerIn, screenWidthIn, screenHeightIn ),
	audioManager( &audioManagerIn ),
	mainMenu( textureCodex, desiredItems, float( screenWidthIn ), float( screenHeightIn ), 0.0f, -25.0f )
{
	title.setTexture( textureCodex.GetMenuTexture( MenuTextureTypes::Title ) );
	title.setPosition( { float( screenWidthIn ) / 2 - title.getTexture()->getSize().x / 2, float( screenHeightIn ) / 2 - title.getTexture()->getSize().y - 25.0f } );
}

void MainMenuState::InitializeState()
{
}

void MainMenuState::ResetState()
{
	mainMenu.ResetOptions();
}

void MainMenuState::Enter()
{
}

void MainMenuState::HandleInput()
{
	mainMenu.HandleInput( *handler, *audioManager );
}

void MainMenuState::UpdateLogic( float frameTime )
{
	mainMenu.Update( frameTime );
}

void MainMenuState::Render( float interpolation )
{
	mainMenu.Render( *window, interpolation );
	window->draw( title );
}