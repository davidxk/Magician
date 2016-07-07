#include "MainLoop.h"

#include <thread>
#include "basic/MagicianMacros.h"
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
		exitScene = false;
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
	// Init
	ts.sceneBegin();
	std::thread keyread( &KeyDispatcher::loop, &kd );
	keyread.detach();

	// Loop
	while( !exitScene )
	{
		update();
		ts.updateTime();
		std::this_thread::sleep_until( ts.getNextFrameTime() );
	}
}

void MainLoop::update()
{
	gScheduler->checkSchedule();
	aManager->update();
	dc.printFrame( vManager->getFrame() );
}

void MainLoop::cleanupScene(Scene* scene)
{
	delete scene;
	sVisibleObjManager::release();
	sActionManager::release();
	sScheduler::release();
	kd.clearStack();
}

MainLoop::~MainLoop()
{
	sVisibleObjManager::release();
	sActionManager::release();
}
