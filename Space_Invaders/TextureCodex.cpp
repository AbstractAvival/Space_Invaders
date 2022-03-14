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
	string menuTextureName;
	ifstream mainMenuTexturesFile( fileName );
	if( mainMenuTexturesFile.is_open() )
	{
		while( getline( mainMenuTexturesFile, menuTextureName ) )
		{
			cout << menuTextureName << endl;
		}
		mainMenuTexturesFile.close();
	}
}

void TextureCodex::LoadGametextures( string fileName )
{
	/*
	string gameTextureName;
	ifstream gameTexturesFile( fileName );
	if( gameTexturesFile.is_open() )
	{
		while( getline( gameTexturesFile, gameTextureName ) )
		{
			cout << gameTextureName << endl;
		}
		gameTexturesFile.close();
	}
	*/
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