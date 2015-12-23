#ifndef _TIME_SERVICE_
#define _TIME_SERVICE_

class TimeService
{
public:
	static int cntCycle;
	static int cntTime;
	static const int TIME_UNIT;

	static void updateTime();
	static int getTime();
	static int getCycle();
}

#endif
