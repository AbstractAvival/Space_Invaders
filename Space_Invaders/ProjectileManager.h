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
	void UpdateProjectiles();
	void RenderProjectiles( sf::RenderWindow& window, float interpolation );

public:
	void ShootPlayerProjectile( sf::Vector2f position );

private:
	void HandlePlayerProjectiles();

private:
	TextureCodex* textureCodex;
	vector< Projectile* > playerProjectiles;
	vector< Projectile* > enemyProjectiles;
	const float playerProjectileSpeed = 12.0f;
	const float enemyProjectileSpeed = 8.0f;
};