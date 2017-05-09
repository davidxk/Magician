#include "Director.h"
#include <thread>

void Director::pushScene(Scene* scene)
{
	if( sceneStack.empty())
	{
		sceneStack.push( scene );
		exitScene = false;
		mainloop();
		cleanupGame();
	}
	else
	{
		sceneStack.top()->pause();
		sceneStack.push( scene );
		exitScene = true;
	}
}

void Director::popScene()
{
	exitScene = true;
}

void Director::replaceScene(Scene* scene)
{
	Scene* replaced = sceneStack.top();
	sceneStack.pop();
	sceneStack.push( scene );
	sceneStack.push( replaced );
	exitScene = true;
}




void Director::loopTopScene()
{
	// Init
	getTimeService()->sceneBegin();

	// Loop
	while( !exitScene )
	{
		update();
		getTimeService()->updateTime();
		std::this_thread::sleep_until( getTimeService()->getNextFrameTime() );
	}
}

void Director::cleanupTopScene()
{
	//sceneStack.top()->stop();
	delete sceneStack.top();
	sceneStack.pop();
}

void Director::mainloop()
{
	std::thread keyread( loop );
	keyread.detach();
	while( !sceneStack.empty() )
	{
		sceneStack.top()->initScene();
		exitScene = false;
		loopTopScene();
		cleanupTopScene();
	}
}

void Director::cleanupGame()
{
	dc.destroyPrinter();
}

void Director::update()
{
	getScheduler()->checkSchedule();
	getActionManager()->update();
	dc.printFrame( getNodeManager()->getFrame( getNodeManager()->getRoot() ) );
}
