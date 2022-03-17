#pragma once
#include <SFML/Graphics.hpp>
#include "TextureCodex.h"
#include "PlayerShip.h"

class PlayerManager
{
public:
	PlayerManager() = default;
	PlayerManager( TextureCodex& textureCodex );
	~PlayerManager();

	void ResetPlayer();
	void UpdatePlayer( int stageWidth, float frameTime );
	void RenderPlayer( sf::RenderWindow& window, float interpolation );

private:
	void HandleUserInput( float frameTime );
	void ImposeStageBoundaryLimits( int stageWidth );

private:
	const sf::Vector2< float > playerStartingPosition = sf::Vector2< float >( 500.0f, 550.0f );
	const float playerSpeed = 5.0f;
	PlayerShip* player = nullptr;
};