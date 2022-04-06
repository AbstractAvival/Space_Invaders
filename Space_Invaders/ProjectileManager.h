#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureCodex.h"
#include "Projectile.h"
#include "EnemyManager.h"
#include "AudioManager.h"

class ProjectileManager
{
public:
	ProjectileManager( TextureCodex& textureCodexIn, AudioManager& audioManagerIn, EnemyManager& enemyManagerIn, class PlayerManager& playerManagerIn );
	~ProjectileManager();
	void UpdateProjectiles( float frameTime, bool playerExploded );
	void RenderProjectiles( sf::RenderWindow& window, float interpolation );
	void ShootPlayerProjectile( sf::Vector2f position );
	void ResetProjectiles();

private:
	void HandlePlayerProjectiles();
	void HandlePlayerShotCollision();
	void HandleEnemyProjectiles();
	void HandleEnemyShotCollision();
	void ShootEnemyProjectile();
	void ClearAllEnemyProjectiles();

private:
	TextureCodex* textureCodex = nullptr;
	EnemyManager* enemyManager = nullptr;
	AudioManager* audioManager = nullptr;
	class PlayerManager* playerManager = nullptr;
	std::vector< Projectile* > playerProjectiles;
	std::vector< Projectile* > enemyProjectiles;
	const float endingPlayerProjectilePosition = 70.0f;
	const float endingEnemyProjectilePosition = 560.0f;
	const float maxEnemyProjectileCooldown = 0.50f;
	float enemyProjectileCooldown = maxEnemyProjectileCooldown;
};