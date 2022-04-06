#pragma once
#include <random>

class RandomNumberGenerator
{
public:
	RandomNumberGenerator();
	int GetRandomInt( int minLimit, int maxLimit );
	float GetRandomFloat( float minLimit, float maxLimit );

private:
	std::mt19937 numberGenerator;
	std::uniform_int_distribution< int > intValues;
	std::uniform_real_distribution< float > floatValues;
};