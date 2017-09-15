#include "Magician.h"

#include "HelloWorld.h"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	Scene* hello = new HelloWorld();
	gDirector->runWithScene( hello );
	return 0;
}
