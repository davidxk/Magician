#include "action/Layer.h"
#include <cassert>
//delete if runAction succeed
#include "basic/TimeService.h"
#include "action/ActionManager.h"
#include "basic/Scheduler.h"

void Layer::addObject(VisibleObject* object)
{
	assert( object != NULL );
	objList.push_back( object );
}

void Layer::runAction(Action* action)
{
	for(const auto& obj: objList)
	{
		Action* copy = action->clone();
		//obj->runAction( copy );
		copy->setHost( obj );
		copy->initWithHost( obj );
		aManager->addAction( copy );
	}
	delete action;
}

void Layer::scheduleAction(Action* action, int period)
{
	for(const auto& obj: objList)
	{
		Action* copy = action->clone();
		//obj->schedule( copy, timepoint );
		copy->setHost( obj );
		copy->initWithHost( obj );
		//Schedule runAction(Action*) with argument
		function<void(Object*)> scheduledAction = std::bind(
				&VisibleObject::runActionWithObject, obj, placeholders::_1);
		gScheduler->schedule( scheduledAction, copy, period );
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
