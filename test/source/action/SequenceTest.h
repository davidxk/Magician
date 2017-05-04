#ifndef _SEQUENCE_TEST_H_
#define _SEQUENCE_TEST_H_

#include "TestCase.h"

//description of the class here
class SequenceTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Sequence Test"; }
private:
	void testWithManager();
};
#endif
