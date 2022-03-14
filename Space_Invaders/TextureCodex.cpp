#include "TextureCodex.h"

TextureCodex::TextureCodex( string menuTextureFileName, string gameTextureFileName, string fontFileName )
{
	LoadMainMenuTextures( menuTextureFileName );
	LoadGametextures( gameTextureFileName );
	LoadFont( fontFileName );
}

TextureCodex::~TextureCodex()
{
	for( auto texture : mainMenuTextures )
	{
		delete texture;
		texture = nullptr;
	}

	for( auto texture : gameTextures )
	{
		delete texture;
		texture = nullptr;
	}

	delete font;
	font = nullptr;
}

void TextureCodex::LoadFont( string fileName )
{
	font = new sf::Font();
	font->loadFromFile( fileName );
}

void TextureCodex::LoadMainMenuTextures( string fileName )
{
}

void TextureCodex::LoadGametextures( string fileName )
{
}

sf::Font& TextureCodex::GetFont()
{
	return *font;
}

sf::Texture& TextureCodex::GetMainMenuTexture( MainMenuSpriteTypes targetTexture )
{
	return *mainMenuTextures[ ( int )targetTexture ];
}

sf::Texture& TextureCodex::GetGameTexture( GameTextureTypes targetTexture)
{
	return *gameTextures[ ( int )targetTexture ];
}