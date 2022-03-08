#include "GameState.h"

GameState::GameState( sf::RenderWindow& windowIn, class StateHandler& handlerIn, int screenWidthIn, int screenHeightIn )
	:
	window( &windowIn ),
	handler( &handlerIn ),
	screenWidth( screenWidthIn ),
	screenHeight( screenHeightIn )
{}