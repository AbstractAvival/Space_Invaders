#include "StateHandler.h"

StateHandler::StateHandler( sf::RenderWindow& window, int screenWidth, int screenHeight )
{
	currentState = StateTypes::MAINMENU;
	lastState = StateTypes::MAINMENU;
}

StateHandler::~StateHandler()
{
	currentState = StateTypes::MAINMENU;
	lastState = StateTypes::MAINMENU;
}

void StateHandler::InitializeBeginningState()
{
	gameStates[ ( int )currentState ].Enter();
}

void StateHandler::ChangeState( StateTypes targetState )
{
	lastState = currentState;
	currentState = targetState;
	gameStates[ ( int )currentState ].Enter();
}

GameState StateHandler::GetCurrentState()
{
	return *gameStates[ ( int )currentState ];
}

GameState StateHandler::GetState( StateTypes targetState )
{
	return *gameStates[ ( int )targetState ];
}