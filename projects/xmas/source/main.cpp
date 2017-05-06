#include "Magician.h"
#include "CoverScene.h"
#include "HelloWorld.h"

int main()
{
	SequentialScene* logo = new Logo();
	SequentialScene* cover = new CoverScene();
	Scene* hello = new HelloWorld();

	logo->setNextScene( cover );
	cover->setNextScene( hello );

	gDirector->runWithScene( logo );

	return 0;
}
