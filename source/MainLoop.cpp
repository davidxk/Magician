#include "MainLoop.h"
#include <chrono>
#include <thread>
#include "display/ActionManager.h"

const int MainLoop::TIME_UNIT = 50;

void MainLoop::readyGo()
{
	//don't know when to stop
	while(1)
	{
		update();
		std::this_thread::sleep_for (std::chrono::milliseconds( TIME_UNIT ));
	}
}

void MainLoop::update()
{
	aManager->update();
	dc.update();
}
