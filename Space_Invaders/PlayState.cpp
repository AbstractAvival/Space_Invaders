#include "PlayState.h"

PlayState::PlayState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, int screenWidthIn, int screenHeightIn )
	:
	GameState( windowIn, handlerIn, screenWidthIn, screenHeightIn ),
	headsUpDisplay( HeadsUpDisplay( textureCodex, "HighScoreLog.txt" ) ),
	enemyManager( EnemyManager( textureCodex, headsUpDisplay ) ),
	playerManager( PlayerManager( textureCodex ) ),
	projectileManager( ProjectileManager( textureCodex, enemyManager ) )
{}

void PlayState::InitializeState()
{
}

void PlayState::ResetState()
{
}

void PlayState::Enter()
{
}

void PlayState::HandleInput()
{
	playerManager.HandlePlayerInput( projectileManager );
}

void PlayState::UpdateLogic( float frameTime )
{
	enemyManager.UpdateEnemies( frameTime );
	playerManager.UpdatePlayer( maxScreenWidth );
	projectileManager.UpdateProjectiles( frameTime );
}

void PlayState::Render( float interpolation )
{
	headsUpDisplay.RenderHUD( *window );
	enemyManager.RenderEnemies( *window, interpolation );
	projectileManager.RenderProjectiles( *window, interpolation );
	playerManager.RenderPlayer( *window, interpolation );
}