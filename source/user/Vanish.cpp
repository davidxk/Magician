#include "user/Vanish.h"
#include "base/Command.h"

Vanish::Vanish(VisibleObject* host): Action(host, 0)
{
	getCmdQueue();
}

Vanish* Vanish::create(VisibleObject* host)
{
	return new Vanish( host );
}

void Vanish::getCmdQueue()
{
	cmdQueue.push( VanishCommand() );
}





Appear::Appear(VisibleObject* host): Action(host, 0)
{
	getCmdQueue();
}

Appear* Appear::create(VisibleObject* host)
{
	return new Appear( host );
}

void Appear::getCmdQueue()
{
	cmdQueue.push( AppearCommand() );
}




//VanishCommand
void VanishCommand::apply(VisibleObject* vo)
{
	vo->isVisible = false;
}

void AppearCommand::apply(VisibleObject* vo)
{
	vo->isVisible = true;
}
