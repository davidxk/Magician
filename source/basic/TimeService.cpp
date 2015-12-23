#include "basic/TimeService.h"

int TimeService::cntCycle = 0;
int TimeService::cntTime = 0;
const int TimeService::TIME_UNIT = 50;



void TimeService::updateTime()
{
	cntCycle++;
	cntTime += TIME_UNIT;
}

void TimeService::clear()
{
	cntCycle = 0;
	cntTime = 0;
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
