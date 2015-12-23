#ifndef _TIME_SERVICE_
#define _TIME_SERVICE_

class TimeService
{
private:
	static int cntCycle;
	static int cntTime;
public:
	static const int TIME_UNIT;
	static void updateTime();
	static void clear();
	static int getTime();
	static int getCycle();
	static int getTimeUnit();
};

#endif
