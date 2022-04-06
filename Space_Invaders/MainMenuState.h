#pragma once
#include <vector>
#include "GameState.h"
#include "StateHandler.h"
#include "Menu.h"

class MainMenuState : public GameState
{
public:
	MainMenuState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, int screenWidthIn, int screenHeightIn );

public:
	void InitializeState() override;
	void ResetState() override;
	void Enter() override;

	void HandleInput() override;
	void UpdateLogic( float frameTime ) override;
	void Render( float interpolation ) override;

private:
	const std::vector< StateTypes > desiredItems = { StateTypes::PLAYSTATE, StateTypes::SETTINGSSTATE };
	Menu mainMenu;
};