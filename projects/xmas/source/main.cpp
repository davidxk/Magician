#include "MainLoop.h"
#include "Logo.h"
#include "CoverScene.h"
#include "BackScene.h"
#include "HelloWorld.h"
#include <thread>
#include <chrono>

int main()
{
	MainLoop ml;
	std::thread refresh( &MainLoop::readyGo, std::ref( ml ) );
	refresh.detach();

	Logo logo;
	CoverScene cover;
	HelloWorld hello;
	BackScene back;

	while(1)
		std::this_thread::sleep_for( std::chrono::minutes( 1 ) );

	return 0;
}
