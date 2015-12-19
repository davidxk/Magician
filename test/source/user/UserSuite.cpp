#include "user/UserSuite.h"
#include "user/UserTest.h"
#include "user/ActionTest.h"

UserSuite::UserSuite()
{
	addTestCase( new ActionTest );
	//addTestCase( new UserTest );
}
