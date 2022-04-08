#pragma once
#include "Menu.h"
#include "StateTypes.h"

class MainMenu : public Menu
{
public:
	MainMenu() = default;
	MainMenu( TextureCodex & textureCodex, std::vector< std::string > items, float screenWidth, float screenHeight );
	MainMenu( TextureCodex & textureCodex, std::vector< std::string > items, float screenWidth, float screenHeight, float xDisplacement, float yDisplacement );
	~MainMenu();

	void HandleInput( class StateHandler& handler ) override;

private:
	StateTypes GetDesiredState();
};