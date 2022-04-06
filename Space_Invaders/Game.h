#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "TextureCodex.h"
#include "StateHandler.h"

class Game
{
public:
	Game( std::string windowName, std::string fontFileName, int screenWidth, int screenHeight );
	~Game();

	void UpdateLogic( float frameTime );
	void Draw( float interpolation );

	bool Running();
	void Quit();

public:
	sf::RenderWindow* window = nullptr;

private:
	void Initialize( std::string windowName, int screenWidth, int screenHeight );
	void CleanUp();
	void HandleEvents();
	void SetupWindow( std::string windowName, int screenWidth, int screenHeight );

private:
	static constexpr int frameRateLimit = 60;
	TextureCodex* textureCodex;
	StateHandler* stateHandler;
	bool isRunning = false;
};