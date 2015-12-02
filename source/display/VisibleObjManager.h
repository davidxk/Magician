
#include "Singleton.hpp"
#include "VisibleObject.h"
#include <vector>

//VisibleObjManger manages a list of all visible objects
class VisibleObjManger
{
public:
	vector<VisibleObject> objList;
	vector<string> getFrame();
};
typedef Singleton<VisibleObjManger> sVisibleObjManger;
#define vManager sVisibleObjManger::instance()
