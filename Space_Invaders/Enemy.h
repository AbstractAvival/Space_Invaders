#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Enemy : GameObject
{
public:
	Enemy( sf::Vector2< int > positionIn );

public:
	void Update() override;
	void Render( sf::RenderWindow& window, float interpolation ) override;
};