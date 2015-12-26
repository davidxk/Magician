#include "Random.h"
#include <cstdlib>

int Random::randomRange(int lower, int higher)
{
	//[lower .. higher-1]
	return lower + rand() % (higher - lower);
}

int Random::randomPositive(int higher)
{
	return randomRange( 0, higher );
}

int Random::randomNegative(int lower)
{
	return randomRange( lower, 0 );
}
