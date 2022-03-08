#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "StateHandler.h"
using namespace std;

class Game
{
public:
	Game( int screenWidth, int screenHeight, string windowName, string fontFileName );
	~Game();

	void UpdateLogic();
	void Draw( float interpolation );

	bool Running();
	void Quit();

public:
	sf::RenderWindow* window = nullptr;

private:
	void Initialize( int screenWidth, int screenHeight, string windowName );
	void CleanUp();
	void HandleEvents();
	void SetupWindow( int screenWidth, int screenHeight, string windowName );

private:
	static constexpr int frameRateLimit = 60;
	StateHandler* stateHandler;
	bool isRunning = false;
};