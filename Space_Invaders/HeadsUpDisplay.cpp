#include "HeadsUpDisplay.h"

HeadsUpDisplay::HeadsUpDisplay( TextureCodex& textureCodex, AudioManager& audioManagerIn, string highScoreFileNameIn )
	:
	highScoreFileName( highScoreFileNameIn ),
	audioManager( &audioManagerIn ),
	currentScore( 0 ),
	currentLives( 3 ),
	highScore( 0 )
{
	InitializeDisplayPositions();
	InitializeScoreDisplays( textureCodex );
	LoadHighScore( highScoreFileName );
	InitializeLivesDisplay( textureCodex );
}

void HeadsUpDisplay::UpdateHUD()
{
	UpdateHighScore();
	CheckIfEarnedNewLife();
}

void HeadsUpDisplay::RenderHUD( sf::RenderWindow& window )
{
	for( int currentTextIndex = 0; currentTextIndex < int( scoreFonts.size() ); currentTextIndex++ )
	{
		window.draw( scoreFonts[ currentTextIndex ] );
	}

	for( int currentLifeIndex = 0; currentLifeIndex < currentLives; currentLifeIndex++ )
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
		accumulatedLifeScore += 50;
		scoreFonts[ 2 ].setString( to_string( currentScore ) );
		break;

	case EnemyTypes::TierOne:
		currentScore += 10;
		accumulatedLifeScore += 10;
		scoreFonts[ 2 ].setString( to_string( currentScore ) );
		break;

	case EnemyTypes::TierTwo:
		currentScore += 20;
		accumulatedLifeScore += 20;
		scoreFonts[ 2 ].setString( to_string( currentScore ) );
		break;

	case EnemyTypes::TierThree:
		currentScore += 30;
		accumulatedLifeScore += 30;
		scoreFonts[ 2 ].setString( to_string( currentScore ) );
		break;
	}
}

void HeadsUpDisplay::ModifyLives( int lifeOffset )
{
	currentLives += lifeOffset;
}

void HeadsUpDisplay::ResetHUD()
{
	SaveHighScore();
	currentLives = 3;
	currentScore = 0;
	scoreFonts[ 2 ].setString( to_string( currentScore ) );
}

int HeadsUpDisplay::GetCurrentLives() const
{
	return currentLives;
}

bool HeadsUpDisplay::IsGameOver()
{
	return currentLives <= 0;
}

void HeadsUpDisplay::LoadHighScore( string fileName )
{
	string LoadedHighScore;
	ifstream highScoreFile( fileName );
	if( highScoreFile.is_open() )
	{
		while( getline( highScoreFile, LoadedHighScore ) )
		{
			highScore = stoi( LoadedHighScore );
			scoreFonts[ 3 ].setString( LoadedHighScore );
		}
		highScoreFile.close();
	}
}

void HeadsUpDisplay::SaveHighScore()
{
	ofstream highScoreFile( highScoreFileName );
	highScoreFile << to_string( highScore );
	highScoreFile.close();
}

void HeadsUpDisplay::UpdateHighScore()
{
	if( currentScore > highScore )
	{
		highScore = currentScore;
		scoreFonts[ 3 ].setString( to_string( highScore ) );
	}
}

void HeadsUpDisplay::CheckIfEarnedNewLife()
{
	if( accumulatedLifeScore > requiredNewLifeScore )
	{
		accumulatedLifeScore -= requiredNewLifeScore;
		requiredNewLifeScore *= 2;
		currentLives += 1;
		audioManager->PlaySound( AudioTypes::NewLife );
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

	scoreFonts[ 2 ].setPosition( sf::Vector2f( displayPositions[ 0 ].x + scoreFonts[ 2 ].getCharacterSize(), displayPositions[ 0 ].y + 20.0f ) );
	scoreFonts[ 2 ].setString( to_string( currentScore ) );

	scoreFonts[ 3 ].setPosition( sf::Vector2f( displayPositions[ 1 ].x + scoreFonts[ 3 ].getCharacterSize(), displayPositions[ 1 ].y + 20.0f ) );
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