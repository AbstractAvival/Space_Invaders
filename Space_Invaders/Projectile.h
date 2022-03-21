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
	Projectile( TextureCodex& textureCodex, sf::Vector2f position, bool isPlayerProjectile );
	void Update( float frameTime ) override;
	void Render( sf::RenderWindow& window, float interpolation ) override;
	sf::FloatRect GetBoundary() override;
	float GetTextureWidth() override;
	float GetTextureHeight() override;
	void Explode();

private:
	void InitializeSprites( TextureCodex& textureCodex, bool isPlayerProjectile );
	void InitializePlayerSprites( TextureCodex& textureCodex );
	void InitializeEnemySprites( TextureCodex& textureCodex );
	void DoExplodingAnimation( float frameTime );

private:
	ProjectileStatus projectileStatus;
	bool isDoingEndingAnimation;
	float remainingTime;
};