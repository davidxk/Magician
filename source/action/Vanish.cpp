#include "action/Vanish.h"
#include "action/Command.h"

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
	cmdQueue.push( new VanishCommand() );
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
	cmdQueue.push( new AppearCommand() );
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
