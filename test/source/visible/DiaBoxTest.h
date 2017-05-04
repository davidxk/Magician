#ifndef _DIA_BOX_TEST_H_
#define _DIA_BOX_TEST_H_

#include "TestCase.h"

//description of the class here
class DiaBoxTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Dialogue Box Test"; }
private:
	void testConstructor();
};
#endif
