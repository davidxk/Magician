#include "base/Action.h"

Action::Action(VisibleObject* aHost, int aDuration, bool aIsRepeat):
	host(aHost), duration(aDuration), isRepeat(aIsRepeat) { }

/*
Action& Action::create(VisibleObject* aHost, int aDuration, bool aIsRepeat)
{
	list<Action>& actionList = aManager->actionList;
	actionList.emplace_back( Action(aHost, aDuration, aIsRepeat) );
	return actionList.back();
}
*/
