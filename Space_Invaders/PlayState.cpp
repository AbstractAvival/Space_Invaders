#include "PlayState.h"

PlayState::PlayState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, AudioManager& audioManagerIn, int screenWidthIn, int screenHeightIn )
	:
	GameState( windowIn, handlerIn, screenWidthIn, screenHeightIn ),
	headsUpDisplay( HeadsUpDisplay( textureCodex, audioManagerIn, "HighScoreLog.txt" ) ),
	enemyManager( EnemyManager( textureCodex, audioManagerIn, headsUpDisplay ) ),
	playerManager( PlayerManager( textureCodex, audioManagerIn, headsUpDisplay ) ),
	projectileManager( ProjectileManager( textureCodex, audioManagerIn, enemyManager, playerManager ) )
{}

void PlayState::InitializeState()
{
}

void PlayState::ResetState()
{
	accumulatedWaitTime = 0.0f;
	headsUpDisplay.ResetHUD();
	enemyManager.ResetEnemies();
	playerManager.ResetPlayer();
	projectileManager.ResetProjectiles();
}

void PlayState::Enter()
{
}

void PlayState::HandleInput()
{
	playerManager.HandlePlayerInput( projectileManager, enemyManager.IsExecutingOpeningFormation() );
}

void PlayState::UpdateLogic( float frameTime )
{
	headsUpDisplay.UpdateHUD();
	enemyManager.UpdateEnemies( frameTime, playerManager.PlayerExploded() );
	playerManager.UpdatePlayer( enemyManager, frameTime, maxScreenWidth );
	projectileManager.UpdateProjectiles( frameTime, playerManager.PlayerExploded() );

	if( headsUpDisplay.IsGameOver() )
	{
		accumulatedWaitTime += frameTime;
		if( accumulatedWaitTime >= gameOverWaitTime )
		{
			handler->ChangeState( StateTypes::MAINMENUSTATE );
		}
	}
}

void PlayState::Render( float interpolation )
{
	headsUpDisplay.RenderHUD( *window );
	enemyManager.RenderEnemies( *window, interpolation );
	projectileManager.RenderProjectiles( *window, interpolation );
	playerManager.RenderPlayer( *window, interpolation );
}