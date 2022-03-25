#include "HeadsUpDisplay.h"

HeadsUpDisplay::HeadsUpDisplay( TextureCodex& textureCodex, string highScoreFileNameIn )
	:
	highScoreFileName( highScoreFileNameIn ),
	currentScore( 0 ),
	currentlives( 3 ),
	highScore( 0 )
{
	InitializeDisplayPositions();
	InitializeScoreDisplays( textureCodex );
	LoadHighScore( highScoreFileName );
	InitializeLivesDisplay( textureCodex );
}

void HeadsUpDisplay::UpdateHUD()
{
}

void HeadsUpDisplay::RenderHUD( sf::RenderWindow& window )
{
	for( int currentTextIndex = 0; currentTextIndex < int( scoreFonts.size() ); currentTextIndex++ )
	{
		window.draw( scoreFonts[ currentTextIndex ] );
	}

	for( int currentLifeIndex = 0; currentLifeIndex < currentlives; currentLifeIndex++ )
	{
		window.draw( lives[ currentLifeIndex ] );
	}
}

void HeadsUpDisplay::ModifyScore( EnemyTypes killedEnemyType )
{
	switch( killedEnemyType )
	{
	case EnemyTypes::Boss:
		currentScore += 50;
		scoreFonts[ 2 ].setString( to_string( currentScore ) );
		break;

	case EnemyTypes::TierOne:
		currentScore += 10;
		scoreFonts[ 2 ].setString( to_string( currentScore ) );
		break;

	case EnemyTypes::TierTwo:
		currentScore += 20;
		scoreFonts[ 2 ].setString( to_string( currentScore ) );
		break;

	case EnemyTypes::TierThree:
		currentScore += 30;
		scoreFonts[ 2 ].setString( to_string( currentScore ) );
		break;
	}
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
	displayPositions.emplace_back( sf::Vector2f( 25.0f, 5.0f ) );
	displayPositions.emplace_back( sf::Vector2f( 350.0f, 5.0f ) );
	displayPositions.emplace_back( sf::Vector2f( 25.0f, 570.0f ) );
}

void HeadsUpDisplay::InitializeScoreDisplays( TextureCodex& textureCodex )
{
	for( int currentTextIndex = 0; currentTextIndex < maxScoreDisplays; currentTextIndex++ )
	{
		scoreFonts.emplace_back( sf::Text() );
		scoreFonts[ currentTextIndex ].setFont( textureCodex.GetFont() );
		scoreFonts[ currentTextIndex ].setCharacterSize( characterSize );
	}

	scoreFonts[ 0 ].setPosition( displayPositions[ 0 ] );
	scoreFonts[ 0 ].setString( "SCORE" );

	scoreFonts[ 1 ].setPosition( displayPositions[ 1 ] );
	scoreFonts[ 1 ].setString( "HIGH-SCORE" );

	scoreFonts[ 2 ].setPosition( sf::Vector2f( displayPositions[ 0 ].x, displayPositions[ 0 ].y + 20.0f ) );
	scoreFonts[ 2 ].setString( to_string( currentScore ) );

	scoreFonts[ 3 ].setPosition( sf::Vector2f( displayPositions[ 1 ].x, displayPositions[ 1 ].y + 20.0f ) );
}

void HeadsUpDisplay::InitializeLivesDisplay( TextureCodex& textureCodex )
{
	for( int currentLifeIndex = 0; currentLifeIndex < maxLives; currentLifeIndex++ )
	{
		lives.emplace_back( sf::Sprite() );
		lives[ currentLifeIndex ].setTexture( textureCodex.GetGameTexture( GameTextureTypes::PlayerShipReduced ) );
		lives[ currentLifeIndex ].setPosition( { displayPositions[ 2 ].x + currentLifeIndex * 70.0f, displayPositions[ 2 ].y } );
	}
}