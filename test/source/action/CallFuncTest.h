#ifndef _CALL_FUNC_TEST_H_
#define _CALL_FUNC_TEST_H_

#include "TestCase.h"

//description of the class here
class CallFuncTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Call Func Test"; }
private:
	void testWithManager();

	void func();
	bool called;
};
#endif
