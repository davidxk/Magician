#include "user/Vanish.h"
#include "base/Command.h"

Vanish::Vanish(VisibleObject* host): Action(host, 0, false)
{
	getCmdQueue();
}

Vanish* Vanish::create(VisibleObject* host)
{
	return new Vanish( host );
}

void Vanish::getCmdQueue()
{
	cmdQueue.push( Command(Command::VANISH) );
}
