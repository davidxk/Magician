#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include "basic/Object.h"
#include "basic/Singleton.cpp"
#include <functional>
#include <mutex>
#include <unordered_map>
#include <vector>
using namespace std;

class FunctionWithArg;

//A Scheduler provides delayed calling service of a given function
class Scheduler
{
public:
	void schedule(function<void()> func, int period);
	void scheduleAfter(function<void()> func, int period);
	void schedule(function<void (Object*)> func, Object* arg, int period);
	void checkSchedule();
private:
	unordered_map<int,vector<function<void()> > > voidList;
	unordered_map<int,vector<FunctionWithArg> > objList;
	mutex mtx;
};



//FunctionWithArg is a internal class of class Scheduler
class FunctionWithArg
{
public: 
	function<void(Object*)> func;
	Object* arg;
};
#endif
