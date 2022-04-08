#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureCodex.h"

class Settings
{
public:
	Settings();
	Settings( TextureCodex& textureCodex, std::vector< std::string > items, float screenWidth, float screenHeight );
	Settings( TextureCodex& textureCodex, std::vector< std::string > items, float screenWidth, float screenHeight, float xDisplacement, float yDisplacement );

private:
	const float estimatedCharacterHeight = 30.0f;
	const float verticalSeparationDistance = 20.0f;
	const float horizontalSeparationDistance = 20.0f;
	const float maxInputCooldown = 0.08f;
	std::vector< sf::Text > items;
	sf::Sprite selector;
	float accumulatedFrameTime = 0.0f;
	int currentItem = 0;
};