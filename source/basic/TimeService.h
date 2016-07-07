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
	int cntCycle = 0;
	chrono::system_clock::time_point begin;
	chrono::system_clock::time_point pauseStartTime;
public:
	static const int TIME_UNIT;
	static const chrono::duration<int,std::ratio<1,1000> > TIME_UNIT_CHRONO;

	void sceneBegin();
	void scenePause();
	void sceneResume();
	void updateTime();
	chrono::system_clock::time_point getNextFrameTime();

	int getTime();
	int getCycle();
	int getTimeUnit();
};

#endif
