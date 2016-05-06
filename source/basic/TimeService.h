#ifndef _TIME_SERVICE_
#define _TIME_SERVICE_

#include <chrono>
#include <ctime>
#include <ratio>
using namespace std;

//TimeService provides global time service to all subsystems
//All time related service should be found here
class TimeService
{
private:
	static int cntCycle;
	static int cntTime;
	static chrono::system_clock::time_point begin;
public:
	static const int TIME_UNIT;
	static const chrono::duration<int,std::ratio<1,1000> > TIME_UNIT_CHRONO;

	static void gameBegin();
	static void updateTime();
	static chrono::system_clock::time_point getNextFrameTime();

	static int getTime();
	static int getCycle();
	static int getTimeUnit();
};

#endif
