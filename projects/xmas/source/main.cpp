#include "MainLoop.h"
#include "Logo.h"
#include "CoverScene.h"
#include "HelloWorld.h"

int main()
{
	Scene* hello = new HelloWorld();
	Scene* cover = new CoverScene();
	Scene* logo = new Logo();
	gMainLoop->runWithScene( logo );

	return 0;
}
