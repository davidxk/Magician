#include "action/ActionSuite.h"
#include "action/ActionTest.h"
#include "action/AgainTest.h"
#include "action/ActionManagerTest.h"
#include "action/CallFuncTest.h"
#include "action/SequenceTest.h"
#include "action/VanishTest.h"
#include "action/WaitTest.h"

ActionSuite::ActionSuite()
{
	addTestCase(new ActionTest);
	addTestCase(new ActionManagerTest);
	addTestCase(new wait_test_space::WaitTest);
	addTestCase(new vanish_test_space::VanishTest);
	addTestCase(new SequenceTest);
	addTestCase(new again_test_space::AgainTest);
	addTestCase(new CallFuncTest);
}
