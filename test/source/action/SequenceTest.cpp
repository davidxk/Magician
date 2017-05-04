#include "action/SequenceTest.h"
#include <cassert>
#include "action/ActionManager.h"
#include "action/Sequence.h"
#include "action/Vanish.h"
#include "display/Node.h"
#include "basic/TimeService.h"

void SequenceTest::run()
{
	testWithManager();
}

void SequenceTest::testWithManager()
{
	Node* host = new Node();
	Vanish* vanish = Vanish::create( host );
	Appear* appear = Appear::create( host );
	Sequence* seq = Sequence::create( vanish, appear );
	ActionManager amgr;
	amgr.addAction( seq );
	amgr.update();
	assert( !host->getIsVisible() );
	amgr.update();
	assert( host->getIsVisible() );
	delete host;
}
