#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureCodex.h"
#include "Sprites.h"
using namespace std;

class GameObject
{
protected:
	GameObject( sf::Vector2f positionIn );

public:
	virtual void Update( float frameTime ) = 0;
	virtual void Render( sf::RenderWindow& window, float interpolation ) = 0;

	sf::Vector2f GetPosition();
	virtual sf::FloatRect GetBoundary();
	virtual float GetTextureWidth();
	virtual float GetTextureHeight();
	void SetPosition( sf::Vector2f newPosition );
	virtual void Move( sf::Vector2f offset );
	void Kill();
	virtual void Revive();
	bool IsDead();

protected:
	void LoadSprites( TextureCodex& textureCodex, GameTextureTypes types[ 3 ] );
	void LoadTestSprite( TextureCodex& textureCodex );

protected:
	Sprites currentSprite;
	vector< sf::Sprite > sprites;
	sf::Vector2f position;
	bool isDead;
};