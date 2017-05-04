#ifndef _NODE_MANAGER_TEST_H_
#define _NODE_MANAGER_TEST_H_

#include "TestCase.h"
#include "display/NodeManager.h"

class NodeManagerTest;

// Define a sub-class of NodeManager who declares the testcase as a friend
class TestableNodeManager: public NodeManager
{
	friend class NodeManagerTest;
};

//description of the class here
class NodeManagerTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Node Manager Test"; }
private:
	void testGetEmptyFrame();
	void testPaintNode();
	void testGetFrame();
	void testZOrder();
};
#endif
