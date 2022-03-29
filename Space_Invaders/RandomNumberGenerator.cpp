#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator()
{
	numberGenerator = mt19937( random_device {}() );
}

int RandomNumberGenerator::GetRandomInt( int minLimit, int maxLimit )
{
	intValues = uniform_int_distribution< int >( minLimit, maxLimit );
	return intValues( numberGenerator );
}

float RandomNumberGenerator::GetRandomFloat( float minLimit, float maxLimit )
{
	floatValues = uniform_real_distribution< float >( minLimit, maxLimit );
	return floatValues( numberGenerator );
}