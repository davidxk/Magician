#include "MainLoop.h"
#include "Logo.h"
#include "HelloWorld.h"
#include <thread>

int main()
{
	MainLoop ml;
	std::thread refresh( &MainLoop::readyGo, std::ref( ml ) );
	refresh.detach();

	Logo logo;

	HelloWorld hello;

	return 0;
}
