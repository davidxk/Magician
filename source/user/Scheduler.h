#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include "base/Singleton.cpp"
#include <functional>
#include <unordered_map>
#include <vector>
using namespace std;

//description of the class here
class Scheduler
{
public:
	void schedule(function<void()>& func, int time);
	void checkSchedule();

	unordered_map<int,vector<function<void()> > > scheduleList;
};
typedef Singleton<Scheduler> sScheduler;
#define gScheduler sScheduler::instance()
#endif
