#include "MainLoop.h"
#include "HelloWorld.h"
#include <thread>

int main()
{
	HelloWorld hello;

	MainLoop ml;
	std::thread refresh( &MainLoop::readyGo, std::ref( ml ) );
	refresh.join();

	return 0;
}
