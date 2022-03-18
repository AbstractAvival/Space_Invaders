#pragma once
#include "GameState.h"
#include "StateHandler.h"
#include "EnemyManager.h"
#include "PlayerManager.h"
#include "HeadsUpDisplay.h"

class PlayState : public GameState
{
public:
	PlayState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, int screenWidthIn, int screenHeightIn );

public:
	void InitializeState() override;
	void ResetState() override;
	void Enter() override;

	void HandleInput() override;
	void UpdateLogic( float frameTime ) override;
	void Render( float interpolation ) override;

private:
	HeadsUpDisplay headsUpDisplay;
	EnemyManager enemyManager;
	PlayerManager playerManager;
};