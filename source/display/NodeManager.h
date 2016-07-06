#ifndef _NODE_MANAGER_H_
#define _NODE_MANAGER_H_

#include "basic/ColoredChar.h"
#include "display/Node.h"
#include "display/VisibleObject.h"

//description of the class here
class NodeManager
{
public:
	Image getFrame(const Node* node);
	void releaseTree(const Node* node);
protected:
	void paintTree(const Node* node, Image& frame);
	void paintNode(const VisibleObject* obj, Image& frame);
	Image getEmptyFrame();
	void verify(Image& frame);
};
#endif
