#ifndef _BASIC_SUITE_H_
#define _BASIC_SUITE_H_

#include "TestSuite.h"

//description of the class here
class BasicSuite: public TestSuite
{
public:
	BasicSuite();
	virtual std::string suiteName() override { return "Basic"; }
};
#endif
