#ifndef __CollisionUtil_H__
#define __CollisionUtil_H__

#include "display/VisibleObject.h"

class CollisionUtil
{
public:
	static bool detectCollision(VisibleObject* obj1, VisibleObject* obj2);
};
#endif
