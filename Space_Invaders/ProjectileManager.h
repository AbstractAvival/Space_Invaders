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
	ProjectileManager( TextureCodex& textureCodexIn, EnemyManager& enemyManagerIn );
	~ProjectileManager();
	void UpdateProjectiles( float frameTime );
	void RenderProjectiles( sf::RenderWindow& window, float interpolation );

public:
	void ShootPlayerProjectile( sf::Vector2f position );

private:
	void HandlePlayerProjectiles();
	void HandleEnemyProjectiles();
	void ShootEnemyProjectile();

private:
	TextureCodex* textureCodex;
	EnemyManager* enemyManager;
	vector< Projectile* > playerProjectiles;
	vector< Projectile* > enemyProjectiles;
	const float endingPlayerProjectilePosition = 70.0f;
	const float endingEnemyProjectilePosition = 560.0f;
	float playerProjectileCooldown = 0.15f;
	float enemyProjectileCooldown = 0.02f;
};