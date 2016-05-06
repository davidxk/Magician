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

void Window::respondKey(int key)
{
	// Call function at map[key]
}
