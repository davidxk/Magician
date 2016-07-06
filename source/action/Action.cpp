#include "action/Action.h"
#include <cassert>
#include "action/ActionManager.h"

Action::Action(Node* aHost, int aDuration, bool aIsRepeat):
	host(aHost), duration(aDuration), isRepeat(aIsRepeat), isPause(false) { }

Action* Action::clone() const
{
	return new Action(*this);
}

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
	host->inAction = false;
}





void Action::addToManager()
{
	aManager->addAction( this );
}

void Action::setHost(Node* host)
{
	assert( host );
	this->host = host;
}
