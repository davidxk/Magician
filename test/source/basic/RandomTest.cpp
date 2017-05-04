#include "basic/RandomTest.h"
#include <cassert>
#include "basic/Random.h"

void RandomTest::run()
{
	testRandomRange();
	testRandomPositive();
	testRandomNegative();
}

void RandomTest::testRandomRange()
{
	int lower = 80, higher = 100;
	int rand = Random::randomRange(lower, lower + 1);
	assert( rand == lower );

	int mid = Random::randomRange(lower, higher);
	assert( mid>=lower && mid<higher );
}

void RandomTest::testRandomPositive()
{
	int positive = 10;
	int rand = Random::randomPositive( positive );
	assert( rand>=0 && rand<positive );
}

void RandomTest::testRandomNegative()
{
	int negative = -10;
	int rand = Random::randomNegative( negative );
	assert( rand>=negative && rand<0 );
}
