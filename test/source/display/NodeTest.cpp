#include "display/NodeTest.h"
#include <cassert>
#include "display/Node.h"
#include "visible/Sprite.h"

void NodeTest::run()
{
	testAddChild();
	testRemoveChild();
	testMovePos();
	testSetPos();
	testSetForeColor();
	testHighlight();
	testFindChildByName();
	testRemoveChildByName();
}

void NodeTest::testAddChild()
{
	// General add Child
	Node* parent = new Node();
    vector<Node*> child;
	for(int i=0; i<7; i++)
		child.push_back( new Node() );
	parent->addChild( child[0] );
	assert( parent->getChildren().front() == child[0] );
	assert( child[0]->getParent() == parent );
	// Add Child remain zOrdered
	child[1]->setZOrder(0), child[2]->setZOrder(1), child[3]->setZOrder(2);
	child[4]->setZOrder(3), child[5]->setZOrder(3), child[6]->setZOrder(5);
	/* int inOrder[] = { 0, 1, 3, 0, 2, 3, 5 }
	 * 0
	 * 0 1
	 * 0 1 3
	 * 0 0 1 3
	 * 0 0 1 2 3
	 * 0 0 1 2 3 3
	 * 0 0 1 2 3 3 5 
	 */
	int seq[] = { 2,4,1,3,5,6 }, index = 0;
	for(int i: seq)
		parent->addChild( child[ i ] );
	for(const auto& it: parent->getChildren())
		assert( it == child[ index++ ] );
	// Delete newed Nodes
	delete parent;
}

void NodeTest::testRemoveChild()
{
	Node* parent = new Node(), *child = new Node();
	parent->addChild( child );
	parent->removeChild( child, false );
	assert( parent->getChildren().empty() );
	assert( child->getParent() == NULL );
	delete parent, delete child;
}

vector<Node*> NodeTest::makeTree()
{
	// Init nodes as Sprites
	Node* root = Sprite::create("graph/moon.txt");
	Node* branchA = Sprite::create("graph/moon.txt");
	Node* branchB = Sprite::create("graph/moon.txt");
	Node* leafA_1 = Sprite::create("graph/moon.txt");
	Node* leafA_2 = Sprite::create("graph/moon.txt"); 
	Node* leafB = Sprite::create("graph/moon.txt");
	// Init Nodes
	branchA->setPos( Coord(10, 20) ), branchA->setName("BranchA");
	leafA_1->setPos( Coord(5, 15) ), leafA_2->setPos( Coord(15, 25) );
	branchB->setPos( Coord(2, 22) ), leafB->setPos( Coord(5, 55) );
	branchB->setForeColor( 2 ), leafB->setColor( 5, 5 );
	// Add Child to make a tree
	root->addChild( branchA ), root->addChild( branchB );
	branchA->addChild( leafA_1 ), branchA->addChild( leafA_2 );
	branchB->addChild( leafB );
	// Make return vector
	Node* nodes[] = { root, branchA, branchB, leafA_1, leafA_2, leafB };
	vector<Node*> ret( nodes, nodes + sizeof(nodes) / sizeof(Node*) );
	return ret;
}




void NodeTest::testMovePos()
{
	vector<Node*> tree = makeTree();
	tree[1]->setPos( Coord(5, 10) );
	tree[1]->movePos( Coord(1, 2) );
	assert( tree[1]->getPos() == Coord(6, 12) );
	delete tree[0];
}

void NodeTest::testSetPos()
{
	vector<Node*> tree = makeTree();
	tree[1]->setPos( Coord(5, 10) );
	assert( tree[0]->getPos() == Coord(0, 0) ); // Root
	assert( tree[1]->getPos() == Coord(5, 10) ); // BranchA
	assert( tree[2]->getPos() == Coord(2, 22) ); // BranchB
	assert( tree[3]->getPos() == Coord(0, 5) ); // LeafA_1
	assert( tree[4]->getPos() == Coord(10, 15) ); // LeafA_2

	tree[0]->setPos( Coord(1, 2) ); // Root
	assert( tree[5]->getPos() == Coord(6, 57) ); // LeafB
	delete tree[0];
}

void NodeTest::testSetForeColor()
{
	vector<Node*> tree = makeTree();
	tree[1]->setForeColor( 3 );
	assert( tree[0]->getImage()[0][0].foreColor == 7 ); // Root
	assert( tree[1]->getImage()[0][0].foreColor == 3 ); // BranchA
	assert( tree[2]->getImage()[0][0].foreColor == 2 ); // BranchB
	assert( tree[3]->getImage()[0][0].foreColor == 3 ); // LeafA_1
	assert( tree[4]->getImage()[0][0].foreColor == 3 ); // LeafA_2

	tree[0]->setForeColor( 4 ); // Root
	assert( tree[5]->getImage()[0][0].foreColor == 4 ); // LeafB
	delete tree[0];
}

void NodeTest::testHighlight()
{
	vector<Node*> tree = makeTree();
	tree[0]->highlight(); // Root
	assert( tree[5]->getImage()[0][0].foreColor == 2 ); // LeafB
	assert( tree[5]->getImage()[0][0].backColor == 2 ); // LeafB
	delete tree[0];
}

void NodeTest::testFindChildByName()
{
	vector<Node*> tree = makeTree();
	assert( tree[0]->findChildByName("BranchA") == tree[1] );
	delete tree[0];
}

void NodeTest::testRemoveChildByName()
{
	vector<Node*> tree = makeTree();
	tree[0]->removeChildByName("BranchA");
	auto children = tree[0]->getChildren();
	for(auto it = children.begin(); it != children.end(); it++)
		assert( (*it) != tree[1] );
	delete tree[0];
}
