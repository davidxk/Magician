#include "Coco.h"

Coco::Coco(const string& fileName): AnimCursor( fileName ) { }

void Coco::respond(Key key)
{
	AnimCursor::respond(key);
	Jump* jump;
	switch( key )
	{
		case ' ': 
			jump = Jump::create(this, getSize().line, 3.0);
			this->runAction(jump);
			break;
	}
}
