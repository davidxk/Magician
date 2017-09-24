#include "CollisionUtil.h"

#include "basic/Coord.h"
#include "display/VisibleObject.h"

#define MAX(x1, x2) x1 > x2 ? x1 : x2
#define MIN(x1, x2) x1 < x2 ? x1 : x2

bool CollisionUtil::detectCollision(VisibleObject* obj1, VisibleObject* obj2)
{
	const Coord upperLeft1 = obj1->getPos();
	const Coord lowerRight1 = obj1->getPos() + obj1->getSize();
	const Coord upperLeft2 = obj2->getPos();
	const Coord lowerRight2 = obj2->getPos() + obj2->getSize();
	int left = MAX(upperLeft1.column, upperLeft2.column);
	int right = MIN(lowerRight1.column, lowerRight2.column);
	int up = MAX(upperLeft1.line, upperLeft2.line);
	int down = MIN(lowerRight1.line, lowerRight2.line);
	return left < right and up < down;
}
