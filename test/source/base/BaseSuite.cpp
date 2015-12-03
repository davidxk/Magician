#include "base/BaseSuite.h"
#include "base/BaseTest.h"

BaseSuite::BaseSuite()
{
	addTestCase(new BaseTest);
}
