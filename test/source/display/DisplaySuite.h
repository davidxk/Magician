#ifndef _DISPLAY_SUITE_H_
#define _DISPLAY_SUITE_H_

#include "TestSuite.h"

//description of the class here
class DisplaySuite: public TestSuite
{
public:
	DisplaySuite();
	virtual std::string suiteName() override { return "Display"; }
};
#endif
