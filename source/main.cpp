#include "MainLoop.h"
#include "Logo.h"
#include "HelloWorld.h"
#include <thread>
#include <chrono>

int main()
{
	MainLoop ml;
	std::thread refresh( &MainLoop::readyGo, std::ref( ml ) );
	refresh.detach();

	//Logo logo;

	//std::this_thread::sleep_for( std::chrono::seconds( 3 ) );
	HelloWorld hello;
	while(1)
		std::this_thread::sleep_for( std::chrono::minutes( 1 ) );

	return 0;
}
