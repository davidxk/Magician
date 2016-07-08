#ifndef _COCO_H_
#define _COCO_H_

#include "Magician.h"

//description of the class here
class Coco: public AnimCursor
{
public:
	Coco(const string& fileName);
	void respond(Key key);
};
#endif
