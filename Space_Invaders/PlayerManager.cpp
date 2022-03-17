#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
}

PlayerManager::PlayerManager( TextureCodex& textureCodex )
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

void PlayerManager::UpdatePlayer( int stageWidth, float frameTime )
{
}

void PlayerManager::RenderPlayer( sf::RenderWindow& window, float interpolation )
{
	player->Render( window, interpolation );
}

void PlayerManager::HandleUserInput( float frameTime )
{
}

void PlayerManager::ImposeStageBoundaryLimits( int stageWidth )
{
	if( player->GetBoundary().getGlobalBounds().left < 0 )
	{
		sf::Vector2< float > newPosition = player->GetPosition();
	}
}
