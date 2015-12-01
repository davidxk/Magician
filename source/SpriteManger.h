

//VisibleObjManger manages a list of all visible objects
class VisibleObjManger
{
public:
	vector<VisibleObject*> objList;
	void addObject( VisibleObject* obj, int zOrder=0 );
	void removeObject( VisibleObject* obj );
};
