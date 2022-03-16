#include "PauseState.h"

PauseState::PauseState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, int screenWidthIn, int screenHeightIn )
	:
	GameState( windowIn, handlerIn, screenWidthIn, screenHeightIn )
{}

void PauseState::InitializeState()
{
}

void PauseState::ResetState()
{
}

void PauseState::Enter()
{
}

void PauseState::HandleInput()
{
}

void PauseState::UpdateLogic( float frameTime )
{
}

void PauseState::Render( float interpolation )
{
}
