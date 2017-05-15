#ifndef _HELLO_WORLD_H_
#define _HELLO_WORLD_H_

#include "Magician.h"
#include <vector>

class Hero: public Cursor
{
public:

}

//description of the class here
class HelloWorld: public Scene
{
public:
	void initScene();
	Image makeMazeImage(const vector<vector<int> >& mzMatrix);
};
#endif
