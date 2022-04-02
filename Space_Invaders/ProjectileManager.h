#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureCodex.h"
#include "Projectile.h"
#include "EnemyManager.h"
using namespace std;

class ProjectileManager
{
public:
	ProjectileManager( TextureCodex& textureCodexIn, EnemyManager& enemyManagerIn, class PlayerManager& playerManagerIn );
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

private:
	TextureCodex* textureCodex;
	EnemyManager* enemyManager;
	class PlayerManager* playerManager;
	vector< Projectile* > playerProjectiles;
	vector< Projectile* > enemyProjectiles;
	const float endingPlayerProjectilePosition = 70.0f;
	const float endingEnemyProjectilePosition = 560.0f;
	const float maxEnemyProjectileCooldown = 0.50f;
	float enemyProjectileCooldown = maxEnemyProjectileCooldown;
};