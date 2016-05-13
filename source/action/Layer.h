#ifndef _LAYER_H_
#define _LAYER_H_

#include "display/VisibleObject.h"
#include "action/Action.h"

//A Layer is a set of Visible objects that runs the same action simultaneously
class Layer
{
public:
	void addObject(VisibleObject* object);
	//void addObject(VisibleObject* object, ...);
	void runAction(Action* action);
	void scheduleAction(Action* action, int timepoint);
	void scheduleActionAfter(Action* action, int period);
	void pauseActions();
	void resumeActions();
	vector<VisibleObject*> objList;
};
#endif
