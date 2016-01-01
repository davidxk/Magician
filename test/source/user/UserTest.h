#ifndef _USER_TEST_H_
#define _USER_TEST_H_

#include "TestCase.h"
#include "user/Sprite.h"
#include <iostream>

//description of the class here
class UserTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "User Test"; }
};
#endif
