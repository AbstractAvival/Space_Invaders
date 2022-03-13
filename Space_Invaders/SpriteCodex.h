#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "MainMenuSpriteTypes.h"
using namespace std;

class SpriteCodex
{
public:
	SpriteCodex( string fileName );
	~SpriteCodex();

	void LoadFont( string fileName );
	void LoadMainMenuSprites( string fileName );
	void LoadGameSprites( string fileName );

	sf::Font& GetFont();
	sf::Sprite& GetMainMenuSprite( MainMenuSpriteTypes targetSprite );
	sf::Sprite& GetGameSprite(  );

private:
};