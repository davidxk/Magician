#include "basic/TimeService.h"

const int TimeService::TIME_UNIT = 50;
const chrono::duration<int,std::ratio<1,1000> > TimeService::TIME_UNIT_CHRONO = 
       chrono::milliseconds( TimeService::TIME_UNIT );

void TimeService::sceneBegin()
{
	begin = chrono::system_clock::now();
	cntCycle = 0;
}

void TimeService::scenePause()
{
	pauseStartTime = chrono::system_clock::now();
}

void TimeService::sceneResume()
{
	chrono::system_clock::time_point pauseEndTime = chrono::system_clock::now();
	chrono::system_clock::duration deltaTime = pauseEndTime - pauseStartTime;
	begin += deltaTime;
}

void TimeService::updateTime()
{
	cntCycle++;
}

chrono::system_clock::time_point TimeService::getNextFrameTime()
{
	return begin + chrono::milliseconds( cntCycle * TIME_UNIT );
}




int TimeService::getTime()
{
	return cntCycle * TIME_UNIT;
}

int TimeService::getCycle()
{
	return cntCycle;
}

int TimeService::getTimeUnit()
{
	return TIME_UNIT;
}
