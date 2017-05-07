#include "TestSuite.h"
#include <iostream>
#include <cstdio>
#include <cstring>
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
	char buf[BUFLEN + 1];
	int len_read = read(pp[0], buf, BUFLEN);
	buf[len_read] = '\0';
	std::cout<<"+ CASE FAIL: "<<it->testName()<<std::endl;
	printErrorMsg(buf, BUFLEN);
	return false;
}

void TestSuite::printErrorMsg(char* buf, const int BUFLEN)
{
	const unsigned LINEBUFLEN = 64;
	char linebuf[LINEBUFLEN + 1];
	linebuf[ LINEBUFLEN ] = '\0';
	unsigned i = 0;
	while(i < strlen(buf))
	{
		strncpy(linebuf, buf + i, LINEBUFLEN);
		printf("    %s\n", linebuf);
		i += LINEBUFLEN;
	}
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
