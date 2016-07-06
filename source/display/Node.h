#ifndef _NODE_H_
#define _NODE_H_

#include "basic/ColoredChar.h"
#include "basic/Coord.h"
#include "display/VisibleObject.h"
#include <list>
#include <string>

class Action;

//description of the class here
class Node: public VisibleObject
{
public:
	virtual void setPos(const Coord cc) override;
	virtual void setForeColor(Color foreColor) override;
	virtual void setBackColor(Color backColor) override;
	virtual void setColor(Color foreColor, Color backColor) override;

	void movePos(const Coord cc);

	void setZOrder(int zOrder);
	int getZOrder() const;
	void setName(const std::string& name);
	std::string getName() const;
	Node* findChildByName(const std::string& name);
	void removeChildByName(const std::string& name);
	void addChild(Node* node);
	void removeChild(Node* node);
	std::list<Node*> getChildren() const;
	void setParent(Node* node);
	Node* getParent() const;

	void runAction(Action* action);
	void runActionWithObject(Object* obj);
	void pauseActions();
	void resumeActions();
protected:
	Node* parent;
	list<Node*> children;
	std::string name;
	int zOrder;
};
#endif
