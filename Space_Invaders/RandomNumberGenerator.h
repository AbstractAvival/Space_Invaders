#pragma once
#include <random>
using namespace std;

class RandomNumberGenerator
{
public:
	RandomNumberGenerator();
	int GetRandomInt( int minLimit, int maxLimit );
	float GetRandomFloat( float minLimit, float maxLimit );

private:
	mt19937 numberGenerator;
	uniform_int_distribution< int > intValues;
	uniform_real_distribution< float > floatValues;
};