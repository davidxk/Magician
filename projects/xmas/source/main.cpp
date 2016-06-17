#include "MainLoop.h"
#include "Logo.h"
#include "CoverScene.h"
#include "BackScene.h"
#include "HelloWorld.h"
#include "LetterScene.h"
#include <thread>
#include <chrono>

int main()
{
	CoverScene* cover = new CoverScene();
	gMainLoop->runWithScene( cover );

	return 0;
}
