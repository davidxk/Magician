#include "TestRoot.h"

#include "basic/BasicSuite.h"
#include "base/BaseSuite.h"
#include "display/DisplaySuite.h"
#include "user/UserSuite.h"

TestRoot::TestRoot()
{
	testSuites.push_back(new BasicSuite);
	testSuites.push_back(new BaseSuite);
	testSuites.push_back(new DisplaySuite);
	testSuites.push_back(new UserSuite);
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
