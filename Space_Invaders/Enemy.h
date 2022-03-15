#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "EnemyTypes.h"

class Enemy : GameObject
{
public:
	Enemy();
	Enemy( TextureCodex& codex, EnemyTypes enemyType, sf::Vector2< int > positionIn );
	~Enemy();

public:
	void Update() override;
	void Render( sf::RenderWindow& window, float interpolation ) override;

private:
	void LoadSprites( TextureCodex& codex, EnemyTypes enemyType );
	void LoadBossSprite( TextureCodex& codex );
	void LoadTierOneSprites( TextureCodex& codex );
	void LoadTierTwoSprites( TextureCodex& codex );
	void LoadTierThreeSprites( TextureCodex& codex );

private:
};