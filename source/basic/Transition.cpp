#include "base/Transition.h"

#include "display/ActionManager.h"
#include "display/VisibleObjManager.h"

void Transition::releasePrev()
{
	aManager->release();
	vManager->release();
}
