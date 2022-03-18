#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "EnemyTypes.h"

class Enemy : public GameObject
{
public:
	Enemy();
	Enemy( TextureCodex& textureCodex, EnemyTypes enemyTypeIn, sf::Vector2f positionIn );
	~Enemy();

public:
	void Update() override;
	void Render( sf::RenderWindow& window, float interpolation ) override;

private:
	void InitializeSprites( TextureCodex& textureCodex );
	void LoadBossSprite( TextureCodex& textureCodex );
	void LoadTierOneSprites( TextureCodex& textureCodex );
	void LoadTierTwoSprites( TextureCodex& textureCodex );
	void LoadTierThreeSprites( TextureCodex& textureCodex );
	void LoadSprites( TextureCodex& textureCodex, GameTextureTypes types[ 3 ] );

private:
	EnemyTypes enemyType;
};