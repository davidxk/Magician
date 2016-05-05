#include "window/WindowManager.h"

void WindowManager::dispatchKeystroke()
{
	while(1)
	{
		int key = KeystrokeListener::listen();
		auto win = windowStack.top();
		win->respondKey( key );
	}
}
