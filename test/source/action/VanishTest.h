#ifndef _VANISH_TEST_H_
#define _VANISH_TEST_H_

#include "TestCase.h"
#include "action/ActionManager.h"

namespace vanish_test_space{
	class VanishTest;
	class TestableActionManager: public ActionManager
	{
		friend class VanishTest;
	};

	//description of the class here
class VanishTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Vanish Test"; }
private:
	void testWithManager();
	void testAppear();
	void testBlink();
};

}
#endif
