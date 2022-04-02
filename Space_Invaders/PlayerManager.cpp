#include "PlayerManager.h"

PlayerManager::PlayerManager( TextureCodex& textureCodex, HeadsUpDisplay& hudDisplayIn )
	:
	hudDisplay( &hudDisplayIn )
{
	player = new PlayerShip( textureCodex, playerStartingPosition );
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
}

void PlayerManager::UpdatePlayer( int stageWidth )
{
	ImposeStageBoundaryLimits( stageWidth );
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
		hudDisplay->ModifyLives( -1 );
		collided = true;
	}
	return collided;
}

bool PlayerManager::PlayerExploded()
{
	return player->GetCurrentSprite() != Sprites::Contract;
}

void PlayerManager::HandlePlayerInput( ProjectileManager& projectileManager )
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