#include "user/Layer.h"
#include <cassert>
//delete if runAction succeed
#include "display/ActionManager.h"

void Layer::addObject(VisibleObject* object)
{
	assert( object != NULL );
	objList.push_back( object );
}

void Layer::runAction(Action* action)
{
	for(const auto& obj: objList)
	{
		//get a copy of the action
		Action* copy = new Action( *action );
		//obj->runAction( copy );
		copy->setHost( obj );
		aManager->addAction( copy );
	}
	delete action;
}

void Layer::pauseActions()
{
	for(const auto& obj: objList)
		obj->pauseActions();
}

void Layer::resumeActions()
{
	for(const auto& obj: objList)
		obj->resumeActions();
}
