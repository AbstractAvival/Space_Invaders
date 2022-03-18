#include "HeadsUpDisplay.h"

HeadsUpDisplay::HeadsUpDisplay( TextureCodex& textureCodex )
	:
	currentScore( 0 ),
	lives( 3 ),
	highScore( 0 )
{
	InitializeDisplayPositions();
	InitializeScoreDisplays( textureCodex );
}

void HeadsUpDisplay::ModifyScore( int scoreOffset )
{
	currentScore += scoreOffset;
}

void HeadsUpDisplay::ModifyLives( int lifeOffset )
{
	lives += lifeOffset;
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
			scoreSprites[ 3 ].setString( highScore );
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
		scoreSprites.emplace_back( sf::Font() );
		scoreSprites[ currentFontIndex ].setFont( textureCodex.GetFont() );
		scoreSprites[ currentFontIndex ].setCharacterSize( 35 );
	}

	scoreSprites[ 0 ].setPosition( displayPositions[ 0 ] );
	scoreSprites[ 0 ].setString( "SCORE" );

	scoreSprites[ 1 ].setPosition( displayPositions[ 1 ] );
	scoreSprites[ 1 ].setString( "HIGH-SCORE" );

	scoreSprites[ 2 ].setPosition( sf::Vector2< float >( displayPositions[ 0 ].x, displayPositions[ 0 ].y + 50.0f ) );
	scoreSprites[ 2 ].setString( to_string( currentScore ) );

	scoreSprites[ 3 ].setPosition( sf::Vector2< float >( displayPositions[ 1 ].x, displayPositions[ 1 ].y + 50.0f ) );
}

void HeadsUpDisplay::InitializeLivesDisplay()
{
}