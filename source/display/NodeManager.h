#ifndef _NODE_MANAGER_H_
#define _NODE_MANAGER_H_

#include "basic/ColoredChar.h"
#include "display/Node.h"
#include "display/VisibleObject.h"

//description of the class here
class NodeManager
{
public:
	NodeManager(): root( new Node() ) { }
	Image getFrame(const Node* node);
	Node* getRoot() const { return root; }
	virtual ~NodeManager() { delete root; }
protected:
	void paintTree(const Node* node, Image& frame);
	void paintNode(const VisibleObject* obj, Image& frame);
	Image getEmptyFrame();
	void verify(Image& frame);

	Node* root;
};
#endif
