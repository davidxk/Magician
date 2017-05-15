#include "Magician.h"

#include "HelloWorld.h"

int main()
{
	Scene* hello = new HelloWorld();
	gDirector->runWithScene( hello );
	return 0;
}
