#ifndef _ACTION_SUITE_H_
#define _ACTION_SUITE_H_

#include "TestSuite.h"

//description of the class here
class ActionSuite: public TestSuite
{
public:
	ActionSuite();
	virtual std::string suiteName() override { return "Action"; }
};
#endif
