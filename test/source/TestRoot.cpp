#include "TestRoot.h"

#include "basic/BasicSuite.h"
#include "base/BaseSuite.h"
#include "display/DisplaySuite.h"

TestRoot::TestRoot()
{
	testSuites.push_back(new BasicSuite);
	testSuites.push_back(new BaseSuite);
	testSuites.push_back(new DisplaySuite);
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
