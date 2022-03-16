#include "StateHandler.h"

StateHandler::StateHandler( sf::RenderWindow& window, TextureCodex& textureCodex, int screenWidth, int screenHeight )
{
	gameStates.emplace_back( new MainMenuState( window, *this, textureCodex, screenWidth, screenHeight ) );
	gameStates.emplace_back( new PauseState( window, *this, textureCodex, screenWidth, screenHeight ) );
	gameStates.emplace_back( new SettingsState( window, *this, textureCodex, screenWidth, screenHeight ) );
	gameStates.emplace_back( new PlayState( window, *this, textureCodex, screenWidth, screenHeight ) );
	currentState = StateTypes::PLAYSTATE;
	lastState = StateTypes::PLAYSTATE;
}

StateHandler::~StateHandler()
{
	for( auto state : gameStates )
	{
		delete state;
		state = nullptr;
	}
	currentState = StateTypes::MAINMENUSTATE;
	lastState = StateTypes::MAINMENUSTATE;
}

void StateHandler::InitializeBeginningState()
{
	gameStates[ int( currentState ) ]->Enter();
}

void StateHandler::ChangeState( StateTypes targetState )
{
	lastState = currentState;
	currentState = targetState;
	gameStates[ int( currentState ) ]->Enter();
}

GameState& StateHandler::GetCurrentState()
{
	return *gameStates[ int( currentState ) ];
}

GameState& StateHandler::GetState( StateTypes targetState )
{
	return *gameStates[ int( targetState ) ];
}