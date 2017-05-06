#include "Magician.h"
#include "CoverScene.h"
#include "HelloWorld.h"

int main()
{
	Scene* hello = new HelloWorld();
	//Scene* cover = new CoverScene();
	//Scene* logo = new Logo();
	gDirector->runWithScene( hello );

	return 0;
}
