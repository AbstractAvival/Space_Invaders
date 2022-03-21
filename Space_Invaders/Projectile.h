#pragma once
#include <SFML/Graphics.hpp>
#include "TextureCodex.h"
#include "GameObject.h"

class Projectile : public GameObject
{
public:
	enum class ProjectileStatus
	{
		Normal,
		Heated,
		Exploded
	};

public:
	Projectile( TextureCodex& textureCodex, sf::Vector2f position );
	void Update() override;
	void Render( sf::RenderWindow& window, float interpolation ) override;

private:
	void InitializeSprites( TextureCodex& textureCodex );

private:
	ProjectileStatus currentSprite;
};