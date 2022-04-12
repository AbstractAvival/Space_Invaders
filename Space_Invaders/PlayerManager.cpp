#include "PlayerManager.h"

PlayerManager::PlayerManager( TextureCodex& textureCodex, AudioManager& audioManagerIn, HeadsUpDisplay& hudDisplayIn )
	:
	hudDisplay( &hudDisplayIn ),
	audioManager( &audioManagerIn )
{
	player = new Player( textureCodex, playerStartingPosition );
}

PlayerManager::~PlayerManager()
{
	delete player;
	player = nullptr;
}

void PlayerManager::ResetPlayer()
{
	player->Revive();
	player->SetPosition( playerStartingPosition );
	accumulatedReviveFrameTime = 0.0f;
}

void PlayerManager::UpdatePlayer( EnemyManager& enemyManager, float frameTime, int stageWidth )
{
	if( PlayerExploded() )
	{
		accumulatedReviveFrameTime += frameTime;
		HandlePlayerExplosionSprites();
		RevivePlayer();
	}
	ImposeStageBoundaryLimits( stageWidth );
	CheckEnemyCollisionAndKill( enemyManager );
}

void PlayerManager::RenderPlayer( sf::RenderWindow& window, float interpolation )
{
	player->Render( window, interpolation );
}

bool PlayerManager::CheckCollisionAndKill( sf::FloatRect enemyShotBoundary )
{
	bool collided = false;
	if( enemyShotBoundary.intersects( player->GetBoundary() ) )
	{
		KillPlayer();
		audioManager->PlaySound( AudioTypes::PlayerExplosion );
		collided = true;
	}
	return collided;
}

bool PlayerManager::PlayerExploded()
{
	return player->GetCurrentSprite() != Sprites::Contract;
}

void PlayerManager::HandlePlayerInput( ProjectileManager& projectileManager, bool enemyIsExecutingOpeningFormation )
{
	if( !PlayerExploded() && !enemyIsExecutingOpeningFormation )
	{
		if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
		{
			player->Move( sf::Vector2f( -playerSpeed, 0.0f ) );
		}

		if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
		{
			player->Move( sf::Vector2f( playerSpeed, 0.0f ) );
		}

		if( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) )
		{
			projectileManager.ShootPlayerProjectile( player->GetPosition() );
		}
	}
}

void PlayerManager::ImposeStageBoundaryLimits( int stageWidth )
{
	if( player->GetBoundary().left < 0 )
	{
		player->SetPosition( sf::Vector2f( 0 + player->GetTextureWidth() / 2, player->GetPosition().y ) );
	}

	if( player->GetBoundary().left + player->GetBoundary().width > stageWidth )
	{
		player->SetPosition( sf::Vector2f( stageWidth - player->GetTextureWidth() / 2, player->GetPosition().y ) );
	}
}

void PlayerManager::HandlePlayerExplosionSprites()
{
	if( player->GetCurrentSprite() == Sprites::Expand )
	{
		player->SetCurrentSprite( Sprites::Explode );
	}
	else
	{
		player->SetCurrentSprite( Sprites::Expand );
	}
}

void PlayerManager::CheckEnemyCollisionAndKill( EnemyManager& enemyManager )
{
	if( enemyManager.CheckCollisionAndKill( player->GetBoundary() ) )
	{
		KillPlayer();
		audioManager->PlaySound( AudioTypes::PlayerExplosion );
	}
}

void PlayerManager::KillPlayer()
{
	hudDisplay->ModifyLives( -1 );
	player->SetCurrentSprite( Sprites::Expand );
}

void PlayerManager::RevivePlayer()
{
	if( !hudDisplay->IsGameOver() && accumulatedReviveFrameTime >= playerReviveCooldown )
	{
		player->Revive();
		player->SetPosition( playerStartingPosition );
		accumulatedReviveFrameTime = 0.0f;
	}
}