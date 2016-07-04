#include "TestRoot.h"

#include "basic/BasicSuite.h"
#include "base/BaseSuite.h"
#include "display/DisplaySuite.h"
#include "visible/VisibleSuite.h"

TestRoot::TestRoot()
{
	testSuites.push_back(new BasicSuite);
	testSuites.push_back(new VisibleSuite);
	testSuites.push_back(new DisplaySuite);
	testSuites.push_back(new BaseSuite);
}

void TestRoot::runAll()
{
	for(const auto& it: testSuites)
		it->runThisSuite();
}

TestRoot::~TestRoot()
{
	for(auto it: testSuites)
		delete it;
}
