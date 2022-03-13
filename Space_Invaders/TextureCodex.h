#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "MainMenuSpriteTypes.h"
#include "GameSpriteTypes.h"
using namespace std;

class TextureCodex
{
public:
	TextureCodex( string fontFileName, string menuSpriteFileName, string gameSpriteFileName );
	~TextureCodex();

	void LoadFont( string fileName );
	void LoadMainMenuSprites( string fileName );
	void LoadGameSprites( string fileName );

	sf::Font& GetFont();
	sf::Sprite& GetMainMenuTexture( MainMenuSpriteTypes targetSprite );
	sf::Sprite& GetGameTexture( GameSpriteTypes targetSprite );

private:
	vector< sf::Texture* > mainMenuTextures;
	vector< sf::Texture* > gameTextures;
	sf::Font* font;
};