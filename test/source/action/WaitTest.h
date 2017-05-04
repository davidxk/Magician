#ifndef _WAIT_TEST_H_
#define _WAIT_TEST_H_

#include "TestCase.h"
#include "action/ActionManager.h"


namespace wait_test_space{
	class WaitTest;
	class TestableActionManager: public ActionManager
	{
		friend class WaitTest;
	};

//description of the class here
class WaitTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Wait Test"; }
private:
	void testWithManager();
};

}
#endif
