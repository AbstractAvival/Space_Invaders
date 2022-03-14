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
	string textureName;
	vector< string > menuTextureNames;
	ifstream mainMenuTexturesFile( fileName );
	if( mainMenuTexturesFile.is_open() )
	{
		while( getline( mainMenuTexturesFile, textureName ) )
		{
			menuTextureNames.emplace_back( textureName );
		}
		mainMenuTexturesFile.close();
	}

	for( int textureIndex = 0; textureIndex != menuTextureNames.size(); textureIndex++ )
	{
		mainMenuTextures.emplace_back( new sf::Texture() );
		mainMenuTextures[ textureIndex ]->loadFromFile( menuTextureNames[ textureIndex ] );
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