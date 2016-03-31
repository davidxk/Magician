#ifndef _VISIBLE_OBJ_MANGER_H_
#define _VISIBLE_OBJ_MANGER_H_

#include "base/Singleton.cpp"
#include "base/VisibleObject.h"
#include <mutex>
#include <string>
#include <vector>

//Visible ObjManager maintains a list of all visible objects
//In each update, it generates a frame accoring to the list
class VisibleObjManager
{
private:
	vector<VisibleObject*> objList;
	mutex mtx;
public:
	vector<string> getFrame();
	void addObject(VisibleObject* object);
	//in future versions, a frame will know how to verify itself
	void verify(vector<string>& frame);
	~VisibleObjManager();
};
typedef Singleton<VisibleObjManager> sVisibleObjManager;
#define vManager sVisibleObjManager::instance()
#endif
