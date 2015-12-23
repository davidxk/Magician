#include "base/Transition.h"

void Transition::releasePrev()
{
	aManager->release();
	vManager->release();
}
