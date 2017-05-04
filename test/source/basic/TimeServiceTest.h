#ifndef _TIME_SERVICE_TEST_H_
#define _TIME_SERVICE_TEST_H_

#include "TestCase.h"

//description of the class here
class TimeServiceTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Time Service Test"; }
private:
	void testPauseResume();
};
#endif
