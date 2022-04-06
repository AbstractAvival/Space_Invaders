#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "StateTypes.h"
#include "TextureCodex.h"

class Menu
{
public:
	Menu() = default;
	Menu( TextureCodex& textureCodex, std::vector< StateTypes > items, float screenWidth, float screenHeight );
	Menu( TextureCodex& textureCodex, std::vector< StateTypes > items, float screenWidth, float screenHeight, float xDisplacement, float yDisplacement );
	~Menu();

	void HandleInput( class StateHandler& handler );
	void Update( float frameTime );
	void Render( sf::RenderWindow& window, float interpolation );
	void ResetOptions();
	int getCurrentMenuItem();

private:
	void InitializeMenuItems( TextureCodex& textureCodex, std::vector< StateTypes > desiredItems );
	void SetMenuItemPositions( float screenWidth, float screenHeight, float xDisplacement, float yDisplacement );
	void SetItemSelectorPosition();
	StateTypes GetDesiredState();
	std::string GetMenuItemText( StateTypes state );

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