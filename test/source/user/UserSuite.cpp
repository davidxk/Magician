#include "user/UserSuite.h"
#include "user/UserTest.h"
#include "user/ActionTest.h"
#include "user/BoxTest.h"

UserSuite::UserSuite()
{
	addTestCase( new ActionTest );
	//addTestCase( new UserTest );
	addTestCase( new BoxTest );
}
