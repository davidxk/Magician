#ifndef _ACTION_MANAGER_TEST_H_
#define _ACTION_MANAGER_TEST_H_

#include "TestCase.h"
#include "action/ActionManager.h"

class ActionManagerTest;

class TestableActionManager: public ActionManager
{
	friend class ActionManagerTest;
};

//description of the class here
class ActionManagerTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override {return "Action Manager Test";}
private:
	void testAddAction();
	void testUpdate();
	void testPauseHost();
};
#endif
