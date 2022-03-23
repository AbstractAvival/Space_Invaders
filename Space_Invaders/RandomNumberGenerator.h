#pragma once
#include <random>
using namespace std;

class RandomNumberGenerator
{
public:
	RandomNumberGenerator();
	int GetRandomInt( int minLimit, int maxLimit );

private:
	random_device randomDevice;
	mt19937 randomNumberGenerator;
};