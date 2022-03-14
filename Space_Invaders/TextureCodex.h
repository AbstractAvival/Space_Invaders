#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "MainMenuSpriteTypes.h"
#include "GameTextureTypes.h"
using namespace std;

class TextureCodex
{
public:
	TextureCodex( string menuSpriteFileName, string gameSpriteFileName, string fontFileName );
	~TextureCodex();

	void LoadFont( string fileName );
	void LoadMainMenuSprites( string fileName );
	void LoadGameSprites( string fileName );

	sf::Font& GetFont();
	sf::Texture& GetMainMenuTexture( MainMenuSpriteTypes targetTexture );
	sf::Texture& GetGameTexture( GameTextureTypes targetTexture );

private:
	vector< sf::Texture* > mainMenuTextures;
	vector< sf::Texture* > gameTextures;
	sf::Font* font = nullptr;
};