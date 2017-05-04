#include "action/VanishTest.h"
#include <cassert>
#include "action/Vanish.h"
#include "display/Node.h"
#include "basic/TimeService.h"

void vanish_test_space::VanishTest::run()
{
	testWithManager();
	testAppear();
}

void vanish_test_space::VanishTest::testWithManager()
{
	Node* host = new Node();
	Vanish* vanish = Vanish::create( host );
	TestableActionManager amgr;
	amgr.addAction( vanish );
	assert( amgr.actionList.size() == 1 );
	assert( host->getIsVisible() );
	amgr.update();
	assert( amgr.actionList.size() == 1 );
	assert( !host->getIsVisible() );
	amgr.update();
	assert( amgr.actionList.size() == 0 );
	delete host;
}

void vanish_test_space::VanishTest::testAppear()
{
	Node* host = new Node();
	host->setIsVisible( false );
	Appear* appear = Appear::create( host );
	TestableActionManager amgr;
	amgr.addAction( appear );
	assert( amgr.actionList.size() == 1 );
	assert( !host->getIsVisible() );
	amgr.update();
	assert( amgr.actionList.size() == 1 );
	assert( host->getIsVisible() );
	amgr.update();
	assert( amgr.actionList.size() == 0 );
	delete host;
}
