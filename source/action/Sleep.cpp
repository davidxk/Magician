#include "action/Sleep.h"
#include "basic/MagicianMacros.h"

Sleep::Sleep(Node* host, int duration): Action(host, duration)
{
	getCmdQueue();
}

Sleep* Sleep::create(Node* host, int duration)
{
	return new Sleep(host, duration);
}

void Sleep::getCmdQueue()
{
	int steps = duration/magician::TIME_UNIT;
	for(int i=0; i<=steps; i++)
		cmdQueue.push( new Command() );
}




// Wait class: better Sleep
Wait::Wait(Node* host, int duration): Action(host, duration)
{
	getCmdQueue();
}

Wait* Wait::create(Node* host, int duration)
{
	return new Wait(host, duration);
}

void Wait::getCmdQueue()
{
	int cycles = duration/magician::TIME_UNIT;
	cmdQueue.push( new WaitCommand( cycles, this ) );
}




// Wait Command
WaitCommand::WaitCommand(int cycles, Action* wait): 
	cntCycle( cycles ), action( wait ) { }

void WaitCommand::apply(Node* vo)
{
	if(cntCycle > 0)
		cntCycle--;
	else
		action->isRepeat = false;
}
