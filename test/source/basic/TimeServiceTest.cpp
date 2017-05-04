#include "basic/TimeServiceTest.h"
#include <cassert>
#include <thread>
#include "basic/TimeService.h"

void TimeServiceTest::run()
{
	testPauseResume();
}

void TimeServiceTest::testPauseResume()
{
	TimeService ts;
	chrono::system_clock::time_point gameOn = chrono::system_clock::now();
	ts.sceneBegin();
	ts.updateTime();
	std::this_thread::sleep_until( ts.getNextFrameTime() );

	ts.scenePause();
	auto randomTime = chrono::milliseconds( 130 );
	std::this_thread::sleep_for( randomTime );
	ts.sceneResume();

	ts.updateTime();
	assert( ts.getNextFrameTime() >= gameOn + randomTime +
			TimeService::TIME_UNIT_CHRONO * 2 );
	assert( ts.getNextFrameTime() <= gameOn + randomTime +
			TimeService::TIME_UNIT_CHRONO * 3 );
}
