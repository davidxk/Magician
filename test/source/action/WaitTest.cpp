#include "action/WaitTest.h"
#include <cassert>
#include "action/Sleep.h"
#include "display/Node.h"
#include "basic/TimeService.h"

void wait_test_space::WaitTest::run()
{
	testWithManager();
}

void wait_test_space::WaitTest::testWithManager()
{
	Node* host = new Node();
	Wait* wait = Wait::create(host, TimeService::TIME_UNIT * 2);
	TestableActionManager amgr;
	amgr.addAction( wait );
	assert( amgr.actionList.size() == 1 );
	amgr.update();
	assert( amgr.actionList.size() == 1 );
	amgr.update();
	assert( amgr.actionList.size() == 1 );
	amgr.update();
	assert( amgr.actionList.size() == 0 );
	delete host;
}
