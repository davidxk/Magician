#include "user/Scheduler.h"

void Scheduler::schedule(function<void()>& func, int time)
{
	int cycle = time / TimeService::TIME_UNIT;
	if (scheduleList.find(cycle) != scheduleList.end())
		scheduleList[ cycle ].push_back( func );
	else 
	{
		vector<function<void()> tmp;
		tmp.push_back( func );
		scheduleList.emplace( cycle, tmp );
	}
}

void Scheduler::checkSchedule()
{
	int cntCycle = TimeService::getCycle();
	if(scheduleList.find(cntCycle) != scheduleList.end())
	{
		for(const auto& func: scheduleList[cntCycle])
			func();
		scheduleList.erase( cntCycle );
	}
}
