#include "PlayerManager.h"

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
	HandleUserInput( frameTime );
	ImposeStageBoundaryLimits( stageWidth );
}

void PlayerManager::RenderPlayer( sf::RenderWindow& window, float interpolation )
{
	player->Render( window, interpolation );
}

void PlayerManager::HandleUserInput( float frameTime )
{
	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
	{
		player->Move( sf::Vector2< float >( -playerSpeed, 0.0f ) );
	}

	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
	{
		player->Move( sf::Vector2< float >( playerSpeed, 0.0f ) );
	}
}

void PlayerManager::ImposeStageBoundaryLimits( int stageWidth )
{
	if( player->GetBoundary().left < 0 )
	{
		player->SetPosition( sf::Vector2< float >( 0 + player->GetTextureWidth() / 2, player->GetPosition().y ) );
	}

	if( player->GetBoundary().left + player->GetBoundary().width > stageWidth )
	{
		player->SetPosition( sf::Vector2< float >( stageWidth - player->GetTextureWidth() / 2, player->GetPosition().y ) );
	}
}