#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "StateTypes.h"
using namespace std;

class Menu
{
public:
	Menu();
	Menu( StateTypes options[], float xDisplacement, float yDisplacement );

	void HandleInput();
	void Render( sf::RenderWindow& window, float interpolation );
	void ResetOptions();
	int getCurrentOption();

private:
	vector< sf::Text* > items;
	int currentOption = 0;
};