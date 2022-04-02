#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "StateTypes.h"
#include "TextureCodex.h"
using namespace std;

class Menu
{
public:
	Menu();
	Menu( TextureCodex& textureCodex, vector< StateTypes > items, float screenWidth, float screenHeight );
	Menu( TextureCodex& textureCodex, vector< StateTypes > items, float screenWidth, float screenHeight, float xDisplacement, float yDisplacement );
	~Menu();

	void HandleInput();
	void Render( sf::RenderWindow& window, float interpolation );
	void ResetOptions();
	int getCurrentMenuItem();

private:
	void InitializeMenuItems( TextureCodex& textureCodex, vector< StateTypes > desiredItems );
	void SetMenuItemPositions( float screenWidth, float screenHeight, float xDisplacement, float yDisplacement );
	void SetItemSelectorPosition();
	string GetMenuItemText( StateTypes state );

private:
	const float estimatedCharacterHeight = 30.0f;
	const float verticalSeparationDistance = 20.0f;
	const float horizontalSeparationDistance = 20.0f;
	vector< sf::Text > items;
	sf::Sprite selector;
	int currentItem = 0;
};