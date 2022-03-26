#pragma once
#include <SFML/Graphics.hpp>
#include "TextureCodex.h"
#include "PlayerShip.h"
#include "ProjectileManager.h"

class PlayerManager
{
public:
	PlayerManager() = default;
	PlayerManager( TextureCodex& textureCodex, HeadsUpDisplay& hudDisplayIn );
	~PlayerManager();

	void ResetPlayer();
	void HandlePlayerInput( ProjectileManager& projectileManager );
	void UpdatePlayer( int stageWidth );
	void RenderPlayer( sf::RenderWindow& window, float interpolation );
	bool CheckCollisionAndKill( sf::FloatRect enemyShotBoundary );

private:
	void ImposeStageBoundaryLimits( int stageWidth );

private:
	const sf::Vector2f playerStartingPosition = sf::Vector2f( 500.0f, 530.0f );
	const float playerSpeed = 11.0f;
	HeadsUpDisplay* hudDisplay = nullptr;
	PlayerShip* player = nullptr;
};