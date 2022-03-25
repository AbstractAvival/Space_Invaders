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
	Enemy( const Enemy& enemy );
	~Enemy();

public:
	void Update( float frameTime ) override;
	void Render( sf::RenderWindow& window, float interpolation ) override;
	void Move( sf::Vector2f offset ) override;
	void SetSprite( int spriteIndex );
	int GetCurrentSprite();
	EnemyTypes GetEnemyType();

private:
	void InitializeSprites( TextureCodex& textureCodex );
	void LoadBossSprite( TextureCodex& textureCodex );
	void LoadTierOneSprites( TextureCodex& textureCodex );
	void LoadTierTwoSprites( TextureCodex& textureCodex );
	void LoadTierThreeSprites( TextureCodex& textureCodex );
	void SwapMovementSprite();

private:
	EnemyTypes enemyType;
};