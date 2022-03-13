#include "TextureCodex.h"

TextureCodex::TextureCodex( string fontFileName, string menuSpriteFileName, string gameSpriteFileName )
{
}

TextureCodex::~TextureCodex()
{
	for( auto texture : mainMenuTextures )
		delete texture;

	for( auto texture : gameTextures )
		delete texture;

	delete font;
	font = nullptr;
}

void TextureCodex::LoadFont( string fileName )
{
	font = new sf::Font();
}

void TextureCodex::LoadMainMenuSprites( string fileName )
{
}

void TextureCodex::LoadGameSprites( string fileName )
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
