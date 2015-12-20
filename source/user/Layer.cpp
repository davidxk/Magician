#include "user/Layer.h"
#include <cassert>
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
		copy->setHost( obj );
		aManager->addAction( copy );
	}
}
