#include "TextureCodex.h"

TextureCodex::TextureCodex( std::string menuTextureFileName, std::string gameTextureFileName, std::string fontFileName )
{
	LoadMainMenuTextures( menuTextureFileName );
	LoadGametextures( gameTextureFileName );
	LoadFont( fontFileName );
}

TextureCodex::~TextureCodex()
{
	for( auto texture : menuTextures )
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

void TextureCodex::LoadFont( std::string fileName )
{
	font = new sf::Font();
	font->loadFromFile( fileName );
}

void TextureCodex::LoadMainMenuTextures( std::string fileName )
{
	std::string textureName;
	std::vector< std::string > menuTextureNames;
	std::ifstream menuTexturesFile( fileName );
	if( menuTexturesFile.is_open() )
	{
		while( getline( menuTexturesFile, textureName ) )
		{
			menuTextureNames.emplace_back( textureName );
		}
		menuTexturesFile.close();
	}

	for( int textureIndex = 0; textureIndex != menuTextureNames.size(); textureIndex++ )
	{
		menuTextures.emplace_back( new sf::Texture() );
		menuTextures[ textureIndex ]->loadFromFile( menuTextureNames[ textureIndex ] );
	}
}

void TextureCodex::LoadGametextures( std::string fileName )
{
	std::string textureName;
	std::vector< std::string > gameTextureNames;
	std::ifstream gameTexturesFile( fileName );
	if( gameTexturesFile.is_open() )
	{
		while( getline( gameTexturesFile, textureName ) )
		{
			gameTextureNames.emplace_back( textureName );
		}
		gameTexturesFile.close();
	}

	for( int textureIndex = 0; textureIndex != gameTextureNames.size(); textureIndex++ )
	{
		gameTextures.emplace_back( new sf::Texture() );
		gameTextures[ textureIndex ]->loadFromFile( gameTextureNames[ textureIndex ] );
	}
}

sf::Font& TextureCodex::GetFont()
{
	return *font;
}

sf::Texture& TextureCodex::GetMenuTexture( MenuTextureTypes targetTexture )
{
	return *menuTextures[ int( targetTexture ) ];
}

sf::Texture& TextureCodex::GetGameTexture( GameTextureTypes targetTexture)
{
	return *gameTextures[ int( targetTexture ) ];
}