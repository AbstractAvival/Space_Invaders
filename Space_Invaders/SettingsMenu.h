#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureCodex.h"
#include "Menu.h"

class SettingsMenu : public Menu
{
public:
	SettingsMenu() = default;
	SettingsMenu( TextureCodex& textureCodex, AudioManager& audioManagerIn, std::vector< std::string > items, float screenWidth, float screenHeight );
	SettingsMenu( TextureCodex& textureCodex, AudioManager& audioManagerIn, std::vector< std::string > items, float screenWidth, float screenHeight, float xDisplacement, float yDisplacement );

private:
};