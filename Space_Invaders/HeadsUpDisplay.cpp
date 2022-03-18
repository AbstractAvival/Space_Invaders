#include "HeadsUpDisplay.h"

HeadsUpDisplay::HeadsUpDisplay(TextureCodex& textureCodex)
{
}

void HeadsUpDisplay::ModifyScore( int scoreOffset )
{
	currentScore += scoreOffset;
}

void HeadsUpDisplay::ModifyLives( int lifeOffset )
{
	lives += lifeOffset;
}

void HeadsUpDisplay::LoadHighScore()
{
}

void HeadsUpDisplay::InitializeScoreDisplays()
{
}

void HeadsUpDisplay::InitializeLivesDisplay()
{
}
