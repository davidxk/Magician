#ifndef _VISIBLE_OBJECT_TEST_H_
#define _VISIBLE_OBJECT_TEST_H_

#include "TestCase.h"

//description of the class here
class VisibleObjectTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Visible Object Test"; }
private:
	void testSetPos();
};
#endif
