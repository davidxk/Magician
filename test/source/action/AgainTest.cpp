#include "action/AgainTest.h"
#include <cassert>
#include "action/Repeat.h"
#include "action/Sequence.h"
#include "action/Vanish.h"
#include "display/Node.h"
#include "basic/TimeService.h"

void again_test_space::AgainTest::run()
{
	testWithManager();
}

void again_test_space::AgainTest::testWithManager()
{
	Node* host = new Node();
	Vanish* vanish = Vanish::create( host );
	Appear* appear = Appear::create( host );
	Sequence* seq = Sequence::create( appear, vanish );
	Again* again = Again::create( seq, 2 );

	TestableActionManager amgr;
	amgr.addAction( again );
	assert( amgr.actionList.size() == 1 );

	amgr.update();
	assert( host->getIsVisible() );
	assert( amgr.actionList.size() == 1 );
	assert( again->isRepeat == true );
	amgr.update();
	assert( !host->getIsVisible() );
	assert( amgr.actionList.size() == 1 );
	assert( again->isRepeat == true );

	amgr.update();
	assert( host->getIsVisible() );
	assert( amgr.actionList.size() == 1 );
	assert( again->isRepeat == false );
	amgr.update();
	assert( !host->getIsVisible() );
	assert( amgr.actionList.size() == 1 );
	assert( again->isRepeat == false );

	amgr.update();
	assert( !host->getIsVisible() );
	assert( amgr.actionList.size() == 0 );
	delete host;
}
