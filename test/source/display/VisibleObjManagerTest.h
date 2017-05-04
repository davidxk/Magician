#ifndef _VISIBLE_OBJ_MANAGER_TEST_H_
#define _VISIBLE_OBJ_MANAGER_TEST_H_

#include "TestCase.h"
#include "display/VisibleObjManager.h"

class VisibleObjManagerTest;

// Define a sub-class of DisplayCentral who declares the testcase as a friend
class TestableVisibleObjManager: public VisibleObjManager
{
	friend class VisibleObjManagerTest;
};

//description of the class here
class VisibleObjManagerTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { 
		return "Visible Object Manager Test"; }
private:
	void testAddObject();
	void testGetFrame();
};
#endif
