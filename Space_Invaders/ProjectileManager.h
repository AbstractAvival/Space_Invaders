#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureCodex.h"
#include "Projectile.h"
using namespace std;

class ProjectileManager
{
public:
	ProjectileManager( TextureCodex& textureCodexIn );
	~ProjectileManager();
	void UpdateProjectiles( float frameTime );
	void RenderProjectiles( sf::RenderWindow& window, float interpolation );

public:
	void ShootPlayerProjectile( sf::Vector2f position );

private:
	void HandlePlayerProjectiles();

private:
	TextureCodex* textureCodex;
	vector< Projectile* > playerProjectiles;
	vector< Projectile* > enemyProjectiles;
	const float endingPlayerProjectilePosition = 70.0f;
	const float endingEnemyProjectilePosition = 560.0f;
};