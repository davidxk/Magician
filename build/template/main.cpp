#include "Magician.h"

// Include your scene here

int main()
{
	SequentialScene* logo = new Logo();
	
	// Create your scene here
	// Set your scene as the next scene as following
	
	// logo->setNextScene( scene );

	gDirector->runWithScene( logo );

	return 0;
}
