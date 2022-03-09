#pragma once
#include "GameState.h"
#include "StateHandler.h"

class PauseState : public GameState
{
public:
	PauseState( sf::RenderWindow& windowIn, StateHandler& handlerIn, int screenWidthIn, int screenHeightIn );

public:
	void InitializeState() override;
	void ResetState() override;
	void Enter() override;

	void HandleInput() override;
	void UpdateLogic() override;
	void Render( float interpolation ) override;

private:
};