#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "TextureCodex.h"

class Menu
{
public:
	Menu() = default;
	Menu( TextureCodex& textureCodex, std::vector< std::string > items, float screenWidth, float screenHeight );
	Menu( TextureCodex& textureCodex, std::vector< std::string > items, float screenWidth, float screenHeight, float xDisplacement, float yDisplacement );

	virtual void HandleInput();
	virtual void Update( float frameTime );
	virtual void Render( sf::RenderWindow& window, float interpolation );
	void ResetOptions();
	int getCurrentMenuItem();

protected:
	virtual void InitializeMenuItems( TextureCodex& textureCodex, std::vector< std::string > desiredItems );
	virtual void SetMenuItemPositions( float screenWidth, float screenHeight, float xDisplacement, float yDisplacement );
	void SetItemSelectorPosition();

protected:
	const float estimatedCharacterHeight = 30.0f;
	const float verticalSeparationDistance = 20.0f;
	const float horizontalSeparationDistance = 20.0f;
	const float maxInputCooldown = 0.08f;
	std::vector< sf::Text > items;
	sf::Sprite selector;
	float accumulatedFrameTime = 0.0f;
	int currentItem = 0;
};