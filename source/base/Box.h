#ifndef _BOX_H_
#define _BOX_H_

#include "base/VisibleObject.h"
#include "basic/Size.h"

//A Box is the visible part of an interactive window on terminal with outline
class Box: public VisibleObject
{
public:
	Box(const Size& size);
	void setSize(const Size& size);
private:
	void getAsciiOutline();
};
#endif
