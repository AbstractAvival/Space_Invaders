#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "StateTypes.h"
using namespace std;

class StateHandler
{
public:
	StateHandler() = default;
	StateHandler( sf::RenderWindow& window, int screenWidth, int screenHeight );
	~StateHandler();

	void InitializeBeginningState();
	void ChangeState( StateTypes targetState );

	GameState GetCurrentState();
	GameState GetState( StateTypes targetState );

private:
	vector< GameState* > gameStates;
	StateTypes currentState;
	StateTypes lastState;
};