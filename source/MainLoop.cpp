#include "MainLoop.h"

#include <chrono>
#include <thread>
#include "basic/MagicianMacros.h"
#include "display/ActionManager.h"
#include "display/VisibleObjManager.h"

const int MainLoop::TIME_UNIT = magician::TIME_UNIT;

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

MainLoop::~MainLoop()
{
	sVisibleObjManager::release();
	sActionManager::release();
}
