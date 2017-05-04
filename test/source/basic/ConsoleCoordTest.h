#ifndef _CONSOLE_COORD_TEST_H_
#define _CONSOLE_COORD_TEST_H_

#include "TestCase.h"

//description of the class here
class ConsoleCoordTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Console Coord Test"; }
private:
	void testConstructor();
};
#endif
