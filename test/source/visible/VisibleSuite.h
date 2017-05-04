#ifndef _VISIBLE_SUITE_H_
#define _VISIBLE_SUITE_H_

#include "TestSuite.h"

//description of the class here
class VisibleSuite: public TestSuite
{
public:
	VisibleSuite();
	virtual std::string suiteName() override { return "Visible"; }
};
#endif
