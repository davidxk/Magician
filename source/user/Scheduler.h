#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include "base/Singleton.cpp"
#include <functional>
#include <mutex>
#include <unordered_map>
#include <vector>
using namespace std;

//description of the class here
class Scheduler
{
public:
	void schedule(function<void()> func, int timepoint);
	void scheduleAfter(function<void()> func, int period);
	void checkSchedule();
private:
	unordered_map<int,vector<function<void()> > > scheduleList;
	mutex mtx;
};
typedef Singleton<Scheduler> sScheduler;
#define gScheduler sScheduler::instance()
#endif
