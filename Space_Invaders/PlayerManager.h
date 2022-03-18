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
	void HandlePlayerInput();
	void UpdatePlayer( int stageWidth );
	void RenderPlayer( sf::RenderWindow& window, float interpolation );

private:
	void ImposeStageBoundaryLimits( int stageWidth );

private:
	const sf::Vector2< float > playerStartingPosition = sf::Vector2< float >( 500.0f, 550.0f );
	const float playerSpeed = 11.0f;
	PlayerShip* player = nullptr;
};