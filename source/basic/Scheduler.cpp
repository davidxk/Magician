#include "Director.h"
#include "basic/Scheduler.h"
#include "basic/TimeService.h"

void Scheduler::schedule(function<void ()> func, int period)
{
	//lock_guard<mutex> lock(mtx);
	int timepoint = period + gDirector->getTimeService()->getTime();
	int cycle = timepoint / TimeService::TIME_UNIT;
	if (voidList.find(cycle) != voidList.end())
		voidList[ cycle ].push_back( func );
	else 
	{
		vector<function<void()> > tmp;
		tmp.push_back( func );
		voidList.emplace( cycle, tmp );
	}
}

void Scheduler::scheduleAfter(function<void ()> func, int period)
{
	schedule( func, period );
}

void Scheduler::schedule(function<void (Object*)> func, Object* arg, int period)
{
	//lock_guard<mutex> lock(mtx);
	FunctionWithArg funcWithArg;
	funcWithArg.func = func, funcWithArg.arg = arg;

	int timepoint = period + gDirector->getTimeService()->getTime();
	int cycle = timepoint / TimeService::TIME_UNIT;
	if (objList.find(cycle) != objList.end())
		objList[ cycle ].push_back( funcWithArg );
	else 
	{
		vector<FunctionWithArg> tmp;
		tmp.push_back( funcWithArg );
		objList.emplace( cycle, tmp );
	}
}

void Scheduler::checkSchedule()
{
	//lock_guard<mutex> lock(mtx);
	int cntCycle = gDirector->getTimeService()->getCycle();
	if(voidList.find(cntCycle) != voidList.end())
	{
		for(const auto& func: voidList[cntCycle])
			func();
		voidList.erase( cntCycle );
	}
	else if(objList.find(cntCycle) != objList.end())
	{
		for(const auto& funcWithArg: objList[cntCycle])
			if( funcWithArg.func )
				funcWithArg.func( funcWithArg.arg );
		objList.erase( cntCycle );
	}
}
