#include "action/Vanish.h"
#include "action/Command.h"

Vanish::Vanish(Node* host): Action(host, 0)
{
	getCmdQueue();
}

Vanish* Vanish::create(Node* host)
{
	return new Vanish( host );
}

void Vanish::getCmdQueue()
{
	cmdQueue.push( new VanishCommand() );
}





Appear::Appear(Node* host): Action(host, 0)
{
	getCmdQueue();
}

Appear* Appear::create(Node* host)
{
	return new Appear( host );
}

void Appear::getCmdQueue()
{
	cmdQueue.push( new AppearCommand() );
}




//VanishCommand
void VanishCommand::apply(Node* vo)
{
	vo->isVisible = false;
}

void AppearCommand::apply(Node* vo)
{
	vo->isVisible = true;
}
