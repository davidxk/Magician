#include "Random.h"
#include <cassert>
#include <cstdlib>

int Random::randomRange(int lower, int higher)
{
	//[lower .. higher-1]
	return lower + rand() % (higher - lower);
}

int Random::randomPositive(int higher)
{
	assert( higher > 0 );
	return randomRange( 0, higher );
}

int Random::randomNegative(int lower)
{
	assert( lower < 0 );
	return randomRange( lower, 0 );
}
