#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator()
{
	numberGenerator = std::mt19937( std::random_device {}() );
}

int RandomNumberGenerator::GetRandomInt( int minLimit, int maxLimit )
{
	intValues = std::uniform_int_distribution< int >( minLimit, maxLimit );
	return intValues( numberGenerator );
}

float RandomNumberGenerator::GetRandomFloat( float minLimit, float maxLimit )
{
	floatValues = std::uniform_real_distribution< float >( minLimit, maxLimit );
	return floatValues( numberGenerator );
}