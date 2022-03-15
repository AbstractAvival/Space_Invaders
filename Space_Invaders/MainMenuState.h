#pragma once
#include "GameState.h"
#include "StateHandler.h"

class MainMenuState : public GameState
{
public:
	MainMenuState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, int screenWidthIn, int screenHeightIn );

public:
	void InitializeState() override;
	void ResetState() override;
	void Enter() override;

	void HandleInput() override;
	void UpdateLogic() override;
	void Render( float interpolation ) override;

private:
};