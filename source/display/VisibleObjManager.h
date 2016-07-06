#ifndef _VISIBLE_OBJ_MANGER_H_
#define _VISIBLE_OBJ_MANGER_H_

#include "basic/Singleton.cpp"
#include "display/VisibleObject.h"
#include <mutex>
#include <string>
#include <vector>

//Visible ObjManager maintains a list of all visible objects
//In each update, it generates a frame according to the list
class VisibleObjManager
{
public:
	Image getFrame();
	void addObject(VisibleObject* object);
	//in future versions, a frame will, perhaps, know how to verify itself
	~VisibleObjManager();

protected: // For testability
	Image getEmptyFrame();
	void verify(Image& frame);

	vector<VisibleObject*> objList;
	mutex mtx;
};
typedef Singleton<VisibleObjManager> sVisibleObjManager;
#define vManager sVisibleObjManager::instance()
#endif
