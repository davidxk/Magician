#ifndef _AUDIO_TEST_H_
#define _AUDIO_TEST_H_

#include "TestCase.h"
#include <iostream>

//description of the class here
class AudioTest: public TestCase
{
public:
	void run();
	virtual std::string testName() override { return "Audio Test"; }
private:
	void go();
};
#endif
