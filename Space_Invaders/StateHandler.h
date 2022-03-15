#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureCodex.h"
#include "StateTypes.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "PauseState.h"
#include "SettingsState.h"
#include "PlayState.h"
using namespace std;

class StateHandler
{
public:
	StateHandler() = default;
	StateHandler( sf::RenderWindow& window, TextureCodex& textureCodex, int screenWidth, int screenHeight );
	~StateHandler();

	void InitializeBeginningState();
	void ChangeState( StateTypes targetState );

	GameState& GetCurrentState();
	GameState& GetState( StateTypes targetState );

private:
	vector< GameState* > gameStates;
	StateTypes currentState;
	StateTypes lastState;
};