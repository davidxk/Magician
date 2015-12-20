#include "MainLoop.h"
#include "Logo.h"
#include "HelloWorld.h"
#include <thread>

int main()
{
	Logo logo;
	//HelloWorld hello;

	MainLoop ml;
	std::thread refresh( &MainLoop::readyGo, std::ref( ml ) );
	refresh.join();

	return 0;
}
