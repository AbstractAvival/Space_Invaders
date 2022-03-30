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

	void HandleInput();
	void Render( sf::RenderWindow& window, float interpolation );
	void ResetOptions();
	int getCurrentOption();

private:
	void InitializeMenuItems( TextureCodex& textureCodex, vector< StateTypes > desiredItems );
	void SetMenuItemPositions( float screenWidth, float screenHeight, float xDisplacement, float yDisplacement );
	void SetItemSelectorPosition();
	string GetMenuItemText( StateTypes state );

private:
	vector< sf::Text* > items;
	int currentOption = 0;
};