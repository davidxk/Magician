#include "basic/Transition.h"

#include "basic/TimeService.h"
#include "action/ActionManager.h"
#include "display/VisibleObjManager.h"

void Transition::releasePrev()
{
	sVisibleObjManager::release();
	sActionManager::release();
}
