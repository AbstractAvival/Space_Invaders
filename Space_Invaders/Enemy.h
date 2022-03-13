#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "TextureCodex.h"

class Enemy : GameObject
{
public:
	Enemy( TextureCodex& codex, sf::Vector2< int > positionIn );

public:
	void Update() override;
	void Render( sf::RenderWindow& window, float interpolation ) override;
};