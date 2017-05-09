#include "control/KeyDispatcher.h"
#include "Director.h"

#if defined(WIN)
#include <conio.h>
#else
#include <ncurses.h>
#endif

KeyDispatcher::KeyDispatcher()
{
#ifndef WIN
	initscr();
	noecho();
	cbreak();
#endif
}

Key translate(int ch)
{
	return (char)ch;
}

int readkey()
{
	return getch();
}

void loop()
{
	int ch;
	Key key;
	while(1)
	{
		ch = readkey();
		key = translate( ch );
		auto dispatcher = gDirector->getKeyDispatcher();
		auto listenerStack = dispatcher->listenerStack;
		if( !listenerStack.empty() )
			listenerStack.top()->respond( key );
	}
}




void KeyDispatcher::pushListener(KeyListener* listener)
{
	listenerStack.push( listener );
}

void KeyDispatcher::popListener()
{
	if( !listenerStack.empty() )
		listenerStack.pop();
}

void KeyDispatcher::clearStack()
{
	while( !listenerStack.empty() )
		listenerStack.pop();
}
