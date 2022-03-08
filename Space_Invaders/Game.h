#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "StateHandler.h"
using namespace std;

class Game
{
public:
	Game( string windowName, string fontFileName, int screenWidth, int screenHeight );
	~Game();

	void UpdateLogic();
	void Draw( float interpolation );

	bool Running();
	void Quit();

public:
	sf::RenderWindow* window = nullptr;

private:
	void Initialize( string windowName, int screenWidth, int screenHeight );
	void CleanUp();
	void HandleEvents();
	void SetupWindow( string windowName, int screenWidth, int screenHeight );

private:
	static constexpr int frameRateLimit = 60;
	StateHandler* stateHandler;
	bool isRunning = false;
};