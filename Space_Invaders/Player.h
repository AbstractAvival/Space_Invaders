#pragma once
#include <SFML/Graphics.hpp>
#include "TextureCodex.h"
#include "GameObject.h"
#include "Sprites.h"

class Player : public GameObject
{
public:
	Player( TextureCodex& textureCodex, sf::Vector2< float > positionIn );

public:
	void Update( float frameTime ) override;
	void Render( sf::RenderWindow& window, float interpolation ) override;
	void SetCurrentSprite( Sprites newSprite );
	void Revive() override;
	Sprites GetCurrentSprite();

private:

};