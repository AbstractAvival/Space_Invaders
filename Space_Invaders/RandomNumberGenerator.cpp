#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator()
{
	randomNumberGenerator = mt19937( randomDevice() );
}

int RandomNumberGenerator::GetRandomInt( int minLimit, int maxLimit )
{
	uniform_int_distribution< int > intValues = uniform_int_distribution< int >( minLimit, maxLimit );
	return intValues( randomNumberGenerator );
}