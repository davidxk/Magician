#include "user/UserSuite.h"
#include "user/UserTest.h"

UserSuite::UserSuite()
{
	addTestCase( new UserTest );
}
