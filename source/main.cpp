#include "MainLoop.h"
#include "HelloWorld.h"
#include <thread>

int main()
{
	MainLoop ml;
	std::thread refresh( &MainLoop::readyGo(), std::ref( ml ) );
	refresh.detach();

	HelloWorld hello;

	return 0;
}
