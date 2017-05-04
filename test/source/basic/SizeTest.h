#ifndef _SIZE_TEST_H_
#define _SIZE_TEST_H_

#include "TestCase.h"

//description of the class here
class SizeTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Size Test"; }
private:
	void testConstructor();
	void testOprEqual();
	void testOprNotEqual();
};
#endif
