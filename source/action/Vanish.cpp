#include "action/Vanish.h"
#include "action/Command.h"
#include "basic/TimeService.h"

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




Blink::Blink(Node* host, int duration, int cnt):
	Action(host, duration), times(cnt)
{
	getCmdQueue();
}

Blink* Blink::create(Node* host, int duration, int cnt)
{
	return new Blink(host, duration, cnt);
}

void Blink::getCmdQueue()
{
	int cycles = duration/TimeService::TIME_UNIT;
	int cycleEach = cycles / (times * 2) - 1;
	for(int i = 0; i < times * 2; i++)
	{
		for(int j = 0; j < cycleEach; j++)
			cmdQueue.push(new Command());
		if(i % 2 == 0)
			cmdQueue.push(new VanishCommand());
		else
			cmdQueue.push(new AppearCommand());
	}
}




//VanishCommand
void VanishCommand::apply(Node* node)
{
	node->setIsVisible( false );
}

void AppearCommand::apply(Node* node)
{
	node->setIsVisible( true );
}
