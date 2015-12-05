#ifndef _VISIBLE_OBJ_MANGER_H_
#define _VISIBLE_OBJ_MANGER_H_

#include "base/Singleton.cpp"
#include "base/VisibleObject.h"
#include <vector>
#include <string>

//VisibleObjManger manages a list of all visible objects
class VisibleObjManger
{
public:
	void addObject(VisibleObject* object);
	vector<VisibleObject*> objList;
	vector<wstring> getFrame();
	void verify(vector<wstring>& frame);
	~VisibleObjManger();
};
typedef Singleton<VisibleObjManger> sVisibleObjManger;
#define vManager sVisibleObjManger::instance()
#endif
