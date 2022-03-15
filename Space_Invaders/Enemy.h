#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "TextureCodex.h"

class Enemy : GameObject
{
private:
	enum class Sprites
	{
		Contract,
		Expand,
		Explode
	};

public:
	Enemy( TextureCodex& codex, sf::Vector2< int > positionIn );
	~Enemy();

public:
	void Update() override;
	void Render( sf::RenderWindow& window, float interpolation ) override;

private:
	void LoadSprites( TextureCodex& codex );

private:
	Sprites currentSprite;
};