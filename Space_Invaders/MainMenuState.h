#pragma once
#include <vector>
#include "GameState.h"
#include "StateHandler.h"
#include "MainMenu.h"

class MainMenuState : public GameState
{
public:
	MainMenuState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, AudioManager& audioManagerIn, int screenWidthIn, int screenHeightIn );

public:
	void InitializeState() override;
	void ResetState() override;
	void Enter() override;

	void HandleInput() override;
	void UpdateLogic( float frameTime ) override;
	void Render( float interpolation ) override;

private:
	const std::vector< std::string > desiredItems = { "Play", "Settings" };
	AudioManager* audioManager;
	MainMenu mainMenu;
	sf::Sprite title;
};