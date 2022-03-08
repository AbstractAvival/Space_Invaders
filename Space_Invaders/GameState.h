#pragma once
#include <SFML/Graphics.hpp>
#include "StateTypes.h"

class GameState
{
protected:
	GameState( sf::RenderWindow& windowIn, class StateHandler& handlerIn, int screenWidthIn, int screenHeightIn );

public:
	virtual void InitializeState() = 0;
	virtual void ResetState() = 0;
	virtual void Enter() = 0;

	virtual void HandleInput() = 0;
	virtual void UpdateLogic() = 0;
	virtual void Render( float interpolation ) = 0;

protected:
	sf::RenderWindow* window;
	class StateHandler* handler;
	bool isInitialized = false;
	int screenWidth = 0;
	int screenHeight = 0;
};