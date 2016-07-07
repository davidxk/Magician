#include "Magician.h"
#include "HelloWorld.h"

int main()
{
	Scene* hello = new HelloWorld();
	Scene* logo = new Logo();
	gMainLoop->runWithScene( hello );

	return 0;
}
