#include "PlayState.h"

PlayState::PlayState( sf::RenderWindow& windowIn, StateHandler& handlerIn, int screenWidthIn, int screenHeightIn )
	:
	GameState( windowIn, handlerIn, screenWidthIn, screenHeightIn )
{}

void PlayState::InitializeState()
{
}

void PlayState::ResetState()
{
}

void PlayState::Enter()
{
}

void PlayState::HandleInput()
{
}

void PlayState::UpdateLogic()
{
}

void PlayState::Render( float interpolation )
{
	float speed = 12.0f * interpolation;
}
