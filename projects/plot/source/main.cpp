#include "Magician.h"
#include "HelloWorld.h"

int main()
{
    Scene* hello = new HelloWorld();
	gMainLoop->runWithScene( hello );
	return 0;
}
