#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class Game
{
public:
	Game( int screenWidth, int screenHeight, string windowName, string fontFileName );
	~Game();

	void UpdateLogic();
	void Draw();

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
	bool isRunning = false;
};