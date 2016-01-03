#include "basic/TimeService.h"

const int TimeService::TIME_UNIT = 50;
const chrono::duration<int,std::ratio<1,1000> > TIME_UNIT_CHRONO = 
	chrono::milliseconds( TimeService::TIME_UNIT );
chrono::system_clock::time_point TimeService::begin = chrono::system_clock::now();
int TimeService::cntCycle = 0;
int TimeService::cntTime = 0;



void TimeService::gameBegin()
{
	begin = chrono::system_clock::now();
}

void TimeService::updateTime()
{
	cntCycle++;
	cntTime += TIME_UNIT;
}

chrono::system_clock::time_point TimeService::getNextFrameTime()
{
	return begin + chrono::milliseconds( cntTime );
}





int TimeService::getTime()
{
	return cntTime;
}

int TimeService::getCycle()
{
	return cntCycle;
}

int TimeService::getTimeUnit()
{
	return TIME_UNIT;
}
