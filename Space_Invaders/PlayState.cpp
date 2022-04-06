#include "PlayState.h"

PlayState::PlayState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, int screenWidthIn, int screenHeightIn )
	:
	GameState( windowIn, handlerIn, screenWidthIn, screenHeightIn ),
	audioManager( "AudioFiles.txt" ),
	headsUpDisplay( HeadsUpDisplay( textureCodex, audioManager, "HighScoreLog.txt" ) ),
	enemyManager( EnemyManager( textureCodex, audioManager, headsUpDisplay ) ),
	playerManager( PlayerManager( textureCodex, audioManager, headsUpDisplay ) ),
	projectileManager( ProjectileManager( textureCodex, audioManager, enemyManager, playerManager ) )
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