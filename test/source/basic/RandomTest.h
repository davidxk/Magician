#ifndef _RANDOM_TEST_H_
#define _RANDOM_TEST_H_

#include "TestCase.h"

//description of the class here
class RandomTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Random Test"; }
private:
	void testRandomRange();
	void testRandomPositive();
	void testRandomNegative();
};
#endif
