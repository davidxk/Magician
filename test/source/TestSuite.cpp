#include "TestSuite.h"
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

int TestSuite::runThisSuite()
{
	std::cout<<"Running test suite: "<<suiteName()<<std::endl;
	int cntPass = 0;
	for(const auto& it: testCases)
	{
		bool isPass = runTestProc( it );
		cntPass += int(isPass);
	}
	std::cout<<std::endl;
	return cntPass;
}

bool TestSuite::runTestProc(TestCase* it)
{
	pid_t pid;
	int pp[2];
	pipe( pp );
	if( (pid = fork()) == 0 )
	{
		dup2(pp[1], 2);
		it->run();
		std::cout<<"  case pass: "<<it->testName()<<std::endl;
		exit(0);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		if( WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS )
			return true;
	}
	const int BUFLEN = 256;
	char buf[BUFLEN];
	read(pp[0], buf, BUFLEN);
	std::cout<<"+ CASE FAIL: "<<it->testName()<<std::endl;
	return false;
}

void TestSuite::addTestCase(TestCase* testcase)
{
	testCases.push_back(testcase);
}

int TestSuite::getTestCaseNum()
{
	return testCases.size();
}

TestSuite::~TestSuite()
{
	for(auto& it: testCases)
		delete it;
}
