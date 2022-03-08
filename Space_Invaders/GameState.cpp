#include "GameState.h"

GameState::GameState( sf::RenderWindow& windowIn, class StateHandler& handlerIn, int screenWidth, int screenHeight )
	:
	window( &windowIn ),
	handler( &handlerIn ),
	maxScreenWidth( screenWidth ),
	maxScreenHeight( screenHeight )
{}