#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "EnemyTypes.h"

class Enemy : GameObject
{
public:
	Enemy();
	Enemy( TextureCodex& textureCodex, EnemyTypes enemyTypeIn, sf::Vector2< int > positionIn );
	~Enemy();

public:
	void Update() override;
	void Render( sf::RenderWindow& window, float interpolation ) override;

private:
	void LoadSprites( TextureCodex& textureCodex );
	void LoadBossSprite( TextureCodex& textureCodex );
	void LoadTierOneSprites( TextureCodex& textureCodex );
	void LoadTierTwoSprites( TextureCodex& textureCodex );
	void LoadTierThreeSprites( TextureCodex& textureCodex );

private:
	EnemyTypes enemyType;
};