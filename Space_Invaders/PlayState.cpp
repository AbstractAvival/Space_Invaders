#include "PlayState.h"

PlayState::PlayState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, int screenWidthIn, int screenHeightIn )
	:
	GameState( windowIn, handlerIn, screenWidthIn, screenHeightIn )
{
	enemy = Enemy( textureCodex, sf::Vector2< int >( 100, 100 ) );
}

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
	enemy.Render( *window, interpolation );
}
