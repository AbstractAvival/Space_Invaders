#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureCodex.h"
using namespace std;

class GameObject
{
protected:
	enum class Sprites
	{
		Contract,
		Expand,
		Explode
	};

protected:
	GameObject( sf::Vector2f positionIn );

public:
	virtual void Update() = 0;
	virtual void Render( sf::RenderWindow& window, float interpolation ) = 0;

	sf::Vector2f GetPosition();
	sf::FloatRect GetBoundary();
	float GetTextureWidth();
	float GetTextureHeight();
	void SetPosition( sf::Vector2f newPosition );
	void Move( sf::Vector2f offset );
	void Kill();
	void Revive();
	bool IsDead();

protected:
	void LoadTestSprite( TextureCodex& textureCodex );

protected:
	Sprites currentSprite;
	vector< sf::Sprite > sprites;
	sf::Vector2f position;
	bool isDead;
};