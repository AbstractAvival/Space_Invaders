#pragma once
#include <SFML/Graphics.hpp>
#include "TextureCodex.h"
#include "PlayerShip.h"
#include "ProjectileManager.h"
#include "Sprites.h"
#include "EnemyManager.h"
#include "AudioManager.h"

class PlayerManager
{
public:
	PlayerManager() = default;
	PlayerManager( TextureCodex& textureCodex, AudioManager& audioManagerIn, HeadsUpDisplay& hudDisplayIn );
	~PlayerManager();

	void ResetPlayer();
	void HandlePlayerInput( ProjectileManager& projectileManager, bool enemyIsExecutingOpeningFormation );
	void UpdatePlayer( EnemyManager& enemyManager, float frameTime, int stageWidth );
	void RenderPlayer( sf::RenderWindow& window, float interpolation );
	bool CheckCollisionAndKill( sf::FloatRect enemyShotBoundary );
	bool PlayerExploded();

private:
	void ImposeStageBoundaryLimits( int stageWidth );
	void HandlePlayerExplosionSprites();
	void CheckEnemyCollisionAndKill( EnemyManager& enemyManager );
	void KillPlayer();
	void RevivePlayer();

private:
	const sf::Vector2f playerStartingPosition = sf::Vector2f( 500.0f, 530.0f );
	const float playerSpeed = 11.0f;
	HeadsUpDisplay* hudDisplay = nullptr;
	AudioManager* audioManager = nullptr;
	PlayerShip* player = nullptr;
	float playerReviveCooldown = 1.0f;
	float accumulatedReviveFrameTime = 0.0f;
};