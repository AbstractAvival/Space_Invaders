#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureCodex.h"
#include "GameObject.h"
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
	TextureCodex* textureCodex;
	vector< GameObject* > playerProjectiles;
};