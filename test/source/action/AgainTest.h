#ifndef _AGAIN_TEST_H_
#define _AGAIN_TEST_H_

#include "TestCase.h"
#include "action/ActionManager.h"

namespace again_test_space{
	class AgainTest;
	class TestableActionManager: public ActionManager
	{
		friend class AgainTest;
	};

//description of the class here
class AgainTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Again Test"; }
private:
	void testWithManager();
};

}
#endif
