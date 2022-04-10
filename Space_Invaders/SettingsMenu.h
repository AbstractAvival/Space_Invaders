#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "StateTypes.h"

class SettingsMenu : public Menu
{
public:
	SettingsMenu() = default;
	SettingsMenu( TextureCodex& textureCodex, AudioManager& audioManagerIn, std::vector< std::string > items, float screenWidth, float screenHeight );
	SettingsMenu( TextureCodex& textureCodex, AudioManager& audioManagerIn, std::vector< std::string > items, float screenWidth, float screenHeight, float xDisplacement, float yDisplacement );

	void Render( sf::RenderWindow& window, float interpolation ) override;
	void HandleInput( class StateHandler& handler );

private:
	void InitializeMenuItems( TextureCodex& textureCodex, std::vector< std::string > desiredItems ) override;
	void SetMenuItemPositions( float screenWidth, float screenHeight, float xDisplacement, float yDisplacement ) override;
	void ModifyVolume( float volumeOffset );

private:
	AudioManager* audioManager;
	std::vector< sf::Text > options;
};