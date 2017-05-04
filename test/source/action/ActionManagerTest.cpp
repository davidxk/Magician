#include "action/ActionManagerTest.h"
#include <cassert>
#include "action/Action.h"
#include "display/Node.h"

void ActionManagerTest::run()
{

}

void ActionManagerTest::testAddAction()
{
	TestableActionManager amgr;
	assert( amgr.actionList.size() == 0 );
	Node node;
	Action action(&node, 0, false);
	amgr.addAction( &action );
	assert( amgr.actionList.size() == 1 );
	assert( node.getInAction() == true );
}

void ActionManagerTest::testUpdate()
{

}

void ActionManagerTest::testPauseHost()
{

}
