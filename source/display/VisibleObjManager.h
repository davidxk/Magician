#ifndef _VISIBLE_OBJ_MANGER_H_
#define _VISIBLE_OBJ_MANGER_H_

#include "base/Singleton.cpp"
#include "base/VisibleObject.h"
#include <vector>
#include <string>

//Visible ObjManager maintains a list of all visible objects
//In each update, it generates a frame accoring to the list
class VisibleObjManager
{
public:
	void addObject(VisibleObject* object);
	vector<VisibleObject*> objList;
	vector<wstring> getFrame();
	//in future versions, a frame will know how to verify itself
	void verify(vector<wstring>& frame);
	~VisibleObjManager();
};
typedef Singleton<VisibleObjManager> sVisibleObjManager;
#define vManager sVisibleObjManager::instance()
#endif
