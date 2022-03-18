#include "HeadsUpDisplay.h"

HeadsUpDisplay::HeadsUpDisplay( TextureCodex& textureCodex, string highScoreFileName )
	:
	currentScore( 0 ),
	currentlives( 3 ),
	highScore( 0 )
{
	InitializeDisplayPositions();
	InitializeScoreDisplays( textureCodex );
	LoadHighScore( highScoreFileName );
}

void HeadsUpDisplay::UpdateHUD()
{
}

void HeadsUpDisplay::RenderHUD( sf::RenderWindow& window )
{
	for( int currentFontIndex = 0; currentFontIndex < int( scoreFonts.size() ); currentFontIndex++ )
	{
		window.draw( scoreFonts[ currentFontIndex ] );
	}

	for( int currentLifeIndex = 0; currentLifeIndex < int( lives.size() );currentLifeIndex++ )
	{
		window.draw( lives[ currentLifeIndex ] );
	}
}

void HeadsUpDisplay::ModifyScore( int scoreOffset )
{
	currentScore += scoreOffset;
}

void HeadsUpDisplay::ModifyLives( int lifeOffset )
{
	currentlives += lifeOffset;
}

void HeadsUpDisplay::LoadHighScore( string fileName )
{
	string highScore;
	ifstream highScoreFile( fileName );
	if( highScoreFile.is_open() )
	{
		while( getline( highScoreFile, highScore ) )
		{
			highScore = stoi( highScore );
			scoreFonts[ 3 ].setString( highScore );
		}
		highScoreFile.close();
	}
}

void HeadsUpDisplay::InitializeDisplayPositions()
{
	displayPositions.emplace_back( sf::Vector2< float >( 25.0f, 25.0f ) );
	displayPositions.emplace_back( sf::Vector2< float >( 370.0f, 25.0f ) );
	displayPositions.emplace_back( sf::Vector2< float >( 570.0f, 25.0f ) );
}

void HeadsUpDisplay::InitializeScoreDisplays( TextureCodex& textureCodex )
{
	for( int currentFontIndex = 0; currentFontIndex < maxScoreDisplays; currentFontIndex++ )
	{
		scoreFonts.emplace_back( sf::Font() );
		scoreFonts[ currentFontIndex ].setFont( textureCodex.GetFont() );
		scoreFonts[ currentFontIndex ].setCharacterSize( 35 );
	}

	scoreFonts[ 0 ].setPosition( displayPositions[ 0 ] );
	scoreFonts[ 0 ].setString( "SCORE" );

	scoreFonts[ 1 ].setPosition( displayPositions[ 1 ] );
	scoreFonts[ 1 ].setString( "HIGH-SCORE" );

	scoreFonts[ 2 ].setPosition( sf::Vector2< float >( displayPositions[ 0 ].x, displayPositions[ 0 ].y + 50.0f ) );
	scoreFonts[ 2 ].setString( to_string( currentScore ) );

	scoreFonts[ 3 ].setPosition( sf::Vector2< float >( displayPositions[ 1 ].x, displayPositions[ 1 ].y + 50.0f ) );
}

void HeadsUpDisplay::InitializeLivesDisplay()
{
}