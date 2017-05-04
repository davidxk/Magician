#ifndef _TEXT_FIELD_TEST_H_
#define _TEXT_FIELD_TEST_H_

#include "TestCase.h"

//description of the class here
class TextFieldTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Text Field Test"; }
private:
	void testCreate();
};
#endif
