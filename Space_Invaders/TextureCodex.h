#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "MenuTextureTypes.h"
#include "GameTextureTypes.h"

class TextureCodex
{
public:
	TextureCodex( std::string menuSpriteFileName, std::string gameSpriteFileName, std::string fontFileName );
	~TextureCodex();

	void LoadFont( std::string fileName );
	void LoadMainMenuTextures( std::string fileName );
	void LoadGametextures( std::string fileName );

	sf::Font& GetFont();
	sf::Texture& GetMenuTexture( MenuTextureTypes targetTexture );
	sf::Texture& GetGameTexture( GameTextureTypes targetTexture );

private:
	std::vector< sf::Texture* > menuTextures;
	std::vector< sf::Texture* > gameTextures;
	sf::Font* font = nullptr;
};