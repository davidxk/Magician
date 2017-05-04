#ifndef _COLORED_CHAR_TEST_H_
#define _COLORED_CHAR_TEST_H_

#include "TestCase.h"

//description of the class here
class ColoredCharTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Colored Char Test"; }
private:
	void testConstructor();
	void testOprEqNeq();
};
#endif
