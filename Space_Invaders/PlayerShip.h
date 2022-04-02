#pragma once
#include <SFML/Graphics.hpp>
#include "TextureCodex.h"
#include "GameObject.h"
#include "Sprites.h"

class PlayerShip : public GameObject
{
public:
	PlayerShip( TextureCodex& textureCodex, sf::Vector2< float > positionIn );

public:
	void Update( float frameTime ) override;
	void Render( sf::RenderWindow& window, float interpolation ) override;
	Sprites GetCurrentSprite();

private:

};