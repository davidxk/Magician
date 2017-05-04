#ifndef _DISPLAY_CENTRAL_TEST_H_
#define _DISPLAY_CENTRAL_TEST_H_

#include "TestCase.h"
#include "display/DisplayCentral.h"

class DisplayCentralTest;

// Define a sub-class of DisplayCentral who declares the testcase as a friend
class TestableDisplayCentral: public DisplayCentral
{
	friend class DisplayCentralTest;
};

//description of the class here
class DisplayCentralTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Display Central Test"; }
private:
	void testSetThisFrame();
	void testGetDiff();
};
#endif
