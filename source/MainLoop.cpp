#include "MainLoop.h"

#include <chrono>
#include <thread>
#include "basic/MagicianMacros.h"
#include "basic/TimeService.h"
#include "action/ActionManager.h"
#include "display/VisibleObjManager.h"
#include "basic/Scheduler.h"

MainLoop::MainLoop(): exit( false ) { }

void MainLoop::readyGo()
{
	TimeService::gameBegin();
	while( !exit )
	{
		checkMsg();
		update();
		TimeService::updateTime();
		std::this_thread::sleep_until( TimeService::getNextFrameTime() );
	}
}

void MainLoop::update()
{
	gScheduler->checkSchedule();
	aManager->update();
	dc.update( vManager->getFrame() );
}

void MainLoop::checkMsg()
{

}

MainLoop::~MainLoop()
{
	sVisibleObjManager::release();
	sActionManager::release();
}
