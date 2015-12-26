#include "MainLoop.h"

#include <chrono>
#include <thread>
#include "basic/MagicianMacros.h"
#include "basic/TimeService.h"
#include "display/ActionManager.h"
#include "display/VisibleObjManager.h"
#include "user/Scheduler.h"

const int MainLoop::TIME_UNIT = TimeService::TIME_UNIT;

MainLoop::MainLoop():
	exit( false ), transitionReady( false ) { }

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
	/*
	std::queue<int>& queue = Mailbox->msgQueue;
	while( !queue->empty() )
	{
		int msg = queue.front();
		switch(msg)
		{
			case Mailbox::EXIT: exit = true; break;
			case Mailbox::TRANSITION: 
								aManager->release();
								vManager->release();
								transitionReady = true;
								//tell transition class that it is good to go on
								//initializing the next scene
								break;
		}
		queue.pop();
	}
	*/
}

MainLoop::~MainLoop()
{
	sVisibleObjManager::release();
	sActionManager::release();
}
