#include "SettingsState.h"

SettingsState::SettingsState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, AudioManager& audioManagerIn, int screenWidthIn, int screenHeightIn )
	:
	GameState( windowIn, handlerIn, screenWidthIn, screenHeightIn ),
	settingsMenu( textureCodex, audioManagerIn, desiredItems, float( screenWidthIn ), float( screenHeightIn ) )
{}

void SettingsState::InitializeState()
{
}

void SettingsState::ResetState()
{
	settingsMenu.ResetOptions();
}

void SettingsState::Enter()
{
}

void SettingsState::HandleInput()
{
	settingsMenu.HandleInput( *handler );
}

void SettingsState::UpdateLogic( float frameTime )
{
	settingsMenu.Update( frameTime );
}

void SettingsState::Render( float interpolation )
{
	settingsMenu.Render( *window, interpolation );
}
