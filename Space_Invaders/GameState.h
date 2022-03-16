#pragma once
#include <SFML/Graphics.hpp>
#include "StateTypes.h"

class GameState
{
protected:
	GameState( sf::RenderWindow& windowIn, class StateHandler& handlerIn, int screenWidth, int screenHeight );

public:
	virtual void InitializeState() = 0;
	virtual void ResetState() = 0;
	virtual void Enter() = 0;

	virtual void HandleInput() = 0;
	virtual void UpdateLogic( float frameTime ) = 0;
	virtual void Render( float interpolation ) = 0;

protected:
	sf::RenderWindow* window;
	class StateHandler* handler;
	bool isInitialized = false;
	int maxScreenWidth = 0;
	int maxScreenHeight = 0;
};