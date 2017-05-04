#ifndef _NODE_TEST_H_
#define _NODE_TEST_H_

#include "TestCase.h"
#include "display/Node.h"
#include <vector>

//description of the class here
class NodeTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Node Test"; }
private:
	vector<Node*> makeTree();
	void releaseTree(vector<Node*> nodes);

	void testAddChild();
	void testRemoveChild();
	void testMovePos();
	void testSetPos();
	void testSetForeColor();
	void testHighlight();
	void testFindChildByName();
	void testRemoveChildByName();
};
#endif
