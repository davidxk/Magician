
#include "Singleton.hpp"
#include <list>

//Action Manager can be globally accessed
class ActionManager
{
public:
	list<Action> actionList;
	//updates sprites' attributes in vManager
	void update();
};
typedef Singleton<ActionManager> sActionManager;
#define aManager sActionManager::instance()
