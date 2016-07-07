#include "control/KeyDispatcher.h"

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

Key KeyDispatcher::translate(int ch)
{
	return (char)ch;
}

int KeyDispatcher::readkey()
{
	return getch();
}

void KeyDispatcher::loop()
{
	int ch;
	while(1)
	{
		ch = readkey();
		Key key = translate( ch );
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
