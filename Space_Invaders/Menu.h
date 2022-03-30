#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "StateTypes.h"
using namespace std;

class Menu
{
public:
	Menu();
	Menu( StateTypes items[], float screenWidth, float screenHeight );
	Menu( StateTypes items[], float screenWidth, float screenHeight, float xDisplacement, float yDisplacement );

	void HandleInput();
	void Render( sf::RenderWindow& window, float interpolation );
	void ResetOptions();
	int getCurrentOption();

private:
	void InitializeMenuItems( StateTypes items[] );
	void SetMenuItemPositions( float screenWidth, float screenHeight, float xDisplacement, float yDisplacement );
	void SetItemSelectorPosition();

private:
	vector< sf::Text* > items;
	int currentOption = 0;
};