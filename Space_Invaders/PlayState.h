#pragma once
#include "GameState.h"
#include "StateHandler.h"
#include "EnemyManager.h"
#include "PlayerManager.h"

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
	static constexpr int stageWidth = 800;
	static constexpr int stageHeight = 600;
	EnemyManager enemyManager;
	PlayerManager playerManager;
};