#ifndef _ORDERED_PAIR_TEST_H_
#define _ORDERED_PAIR_TEST_H_

#include "TestCase.h"

//description of the class here
class OrderedPairTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Ordered Pair Test"; }
private:
	void testConstructor();
};
#endif
