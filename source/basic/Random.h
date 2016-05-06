#ifndef _RANDOM_H_
#define _RANDOM_H_

//include here

//random is not part of the design yet
class Random
{
public:
	static int randomRange(int lower, int higher);
	static int randomPositive(int higher);
	static int randomNegative(int lower);
};
#endif
