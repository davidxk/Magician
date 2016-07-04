#include "display/VisibleObject.h"

#include <cassert>
#include "action/ActionManager.h"
#include "display/VisibleObjManager.h"

VisibleObject::VisibleObject():
	zOrder(0), isVisible(true), inAction(false) { }

void VisibleObject::verify()
{
	//A visible object should be verified before being registered 
	//Only registered objects are printed
	assert(size.line > 0);
	assert(size.column > 0);
	assert( center==( pos + size )/2 );

	assert(size.line == image.size());
	for(const auto& it: image)
		assert(size.column == it.size());
}

void VisibleObject::addToManager()
{
	vManager->addObject( this );
}

void VisibleObject::setPos(const Coord cc)
{
	//lock_guard<mutex> lock(mtx);
	this->pos = cc;
}

Coord VisibleObject::getPos() const
{
	//lock_guard<mutex> lock(mtx);
	return pos;
}

void VisibleObject::setCenterPos(const Coord cc)
{
	setPos( cc - center );
}

void VisibleObject::updateCenter()
{
	center = ( pos + size )/2;
}




void VisibleObject::runAction(Action* action)
{
	action->setHost( this );
	if( action->host != this ) 
		action->initWithHost( this );
	aManager->addAction( action );
}

void VisibleObject::runActionWithObject(Object* obj)
{
	Action* action = (Action*) obj;
	runAction( action );
}

void VisibleObject::pauseActions()
{
	aManager->pauseHost( this );
}

void VisibleObject::resumeActions()
{
	aManager->resumeHost( this );
}
