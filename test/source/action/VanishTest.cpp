#include "action/VanishTest.h"
#include <cassert>
#include "action/Vanish.h"
#include "display/Node.h"
#include "basic/TimeService.h"

void vanish_test_space::VanishTest::run()
{
	testWithManager();
	testAppear();
	testBlink();
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

void vanish_test_space::VanishTest::testBlink()
{
	Node* host = new Node();
	host->setIsVisible( true );
	const int duration = 2000, cnt = 2;
	Blink* blink = Blink::create( host, duration, cnt );
	TestableActionManager amgr;
	amgr.addAction( blink );
	int count = 0;
	int steps = duration / TimeService::TIME_UNIT;
	for(int i = 0; i < steps; i++)
	{
		amgr.update();
		if(host->getIsVisible() == false)
		{
			count += 1;
			assert(i > 0 and i != steps - 1);
			assert(steps/4 - 3 <= i && i <= steps/2 + 3 or 3*steps/4 - 3 <= i);
		}
	}
	assert( count * 1.0f/ steps <= 0.5f and count * 1.0f/ steps > 0.35f );
}
