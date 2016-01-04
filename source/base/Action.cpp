#include "base/Action.h"
#include <cassert>
#include "display/ActionManager.h"

Action::Action(VisibleObject* aHost, int aDuration, bool aIsRepeat):
	host(aHost), duration(aDuration), isRepeat(aIsRepeat), isPause(false) { }

void Action::pause()
{
	isPause = true;
}

void Action::resume()
{
	isPause = false;
}

void Action::stop()
{
	while( !cmdQueue.empty() )
		cmdQueue.pop();
}





void Action::addToManager()
{
	aManager->addAction( this );
}

void Action::setHost(VisibleObject* host)
{
	assert( host );
	this->host = host;
}
