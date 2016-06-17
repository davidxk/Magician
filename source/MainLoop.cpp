#include "MainLoop.h"

#include <chrono>
#include <thread>
#include "basic/MagicianMacros.h"
#include "basic/TimeService.h"
#include "action/ActionManager.h"
#include "display/VisibleObjManager.h"
#include "basic/Scheduler.h"

MainLoop::MainLoop(): exitScene( false ) { }

void MainLoop::runWithScene(Scene* scene)
{
	nextScene = scene;
	while( nextScene )
	{
		runningScene = nextScene;
		nextScene = nullptr;
		runningScene->initScene();
		loopScene();
		cleanupScene(runningScene);
	}
}

void MainLoop::replaceScene(Scene* scene)
{
	exitScene = true;
	nextScene = scene;
}

void MainLoop::end()
{
	exitScene = true;
	nextScene = nullptr;
}



void MainLoop::loopScene()
{
	TimeService::gameBegin();
	while( !exitScene )
	{
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

void MainLoop::cleanupScene(Scene* scene)
{
	delete scene;
	sVisibleObjManager::release();
	sActionManager::release();
	sScheduler::release();
}

MainLoop::~MainLoop()
{
	sVisibleObjManager::release();
	sActionManager::release();
}
