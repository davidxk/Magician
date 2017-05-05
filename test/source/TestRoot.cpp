#include "TestRoot.h"

#include "action/ActionSuite.h"
#include "basic/BasicSuite.h"
#include "display/DisplaySuite.h"
#include "visible/VisibleSuite.h"
#include <iostream>

TestRoot::TestRoot()
{
	testSuites.push_back(new BasicSuite);
	testSuites.push_back(new VisibleSuite);
	testSuites.push_back(new DisplaySuite);
	testSuites.push_back(new ActionSuite);
}

void TestRoot::runAll()
{
	int cntPass = 0;
	int cntTest = 0;
	for(const auto& it: testSuites)
	{
		cntPass += it->runThisSuite();
		cntTest += it->getTestCaseNum();
	}
	std::cout<<"Summary: "<<cntPass<<" pass out of "<<cntTest<<std::endl;
}

TestRoot::~TestRoot()
{
	for(auto it: testSuites)
		delete it;
}
