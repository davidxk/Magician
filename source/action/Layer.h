#ifndef _LAYER_H_
#define _LAYER_H_

#include "display/Node.h"
#include "action/Action.h"

//A Layer is a set of Visible objects that runs the same action simultaneously
class Layer
{
public:
	void addObject(Node* object);
	//void addObject(Node* object, ...);
	void runAction(Action* action);
	void scheduleAction(Action* action, int period);
	void pauseActions();
	void resumeActions();
	vector<Node*> objList;
};
#endif
