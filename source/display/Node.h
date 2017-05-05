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
	Node();
	virtual ~Node();
	void movePos(const Coord cc);

	virtual void setPos(const Coord cc) override;
	virtual void setIsVisible(bool isVisible) override;
	virtual void setForeColor(Color foreColor) override;
	virtual void setBackColor(Color backColor) override;
	virtual void setColor(Color foreColor, Color backColor) override;
	virtual void highlight() override;

	void setZOrder(int zOrder);
	int getZOrder() const;
	void setInAction(bool inAction);
	bool getInAction() const;
	void setParent(Node* node);
	Node* getParent() const;
	void setName(const std::string& name);
	string getName() const;

	Node* findChildByName(const std::string& name);
	void removeChildByName(const std::string& name);
	void addChild(Node* node);
	void removeChild(Node* node, bool cleanup = true);
	list<Node*> getChildren() const;

	void runAction(Action* action);
	void runActionWithObject(Object* obj);
	void pauseActions();
	void resumeActions();
protected:
	Node* parent;
	list<Node*> children;
	string name;
	int zOrder;
	bool inAction;
};
#endif
