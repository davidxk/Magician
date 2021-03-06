#include "display/Node.h"
#include "Director.h"

Node::Node(): parent(NULL), zOrder(0), inAction(false) { }

Node::~Node()
{
	for(Node* child: children)
		delete child;
}

void Node::movePos(const Coord delta)
{
	pos += delta;
	for(auto& child: children)
		child->movePos( delta );
}




void Node::setPos(const Coord cc)
{
	Coord delta = cc - pos;
	movePos( delta );
}

void Node::setIsVisible(bool isVisible)
{
	VisibleObject::setIsVisible( isVisible );
	for(const auto& child: children)
		child->setIsVisible( isVisible );
}

void Node::setForeColor(Color foreColor)
{
	VisibleObject::setForeColor( foreColor );
	for(const auto& child: children)
		child->setForeColor( foreColor );
}

void Node::setBackColor(Color backColor)
{
	VisibleObject::setBackColor( backColor );
	for(const auto& child: children)
		child->setBackColor( backColor );
}

void Node::setColor(Color foreColor, Color backColor)
{
	VisibleObject::setColor( foreColor, backColor );
	for(const auto& child: children)
		child->setColor( foreColor, backColor );
}

void Node::highlight()
{
	VisibleObject::highlight();
	for(const auto& child: children)
		child->highlight();
}




void Node::setZOrder(int zOrder)
{
	this->zOrder = zOrder;
}

int Node::getZOrder() const
{
	return zOrder;
}

void Node::setInAction(bool inAction)
{
	this->inAction = inAction;
}

bool Node::getInAction() const
{
	return inAction;
}

void Node::setParent(Node* node)
{
	this->parent = node;
}

Node* Node::getParent() const
{
	return parent;
}

void Node::setName(const std::string& name)
{
	this->name = name;
}

std::string Node::getName() const
{
	return name;
}




Node* Node::findChildByName(const std::string& name)
{
	for(const auto& child: children)
		if(child->getName() == name)
			return child;
	return NULL;
}

void Node::removeChildByName(const std::string& name)
{
	for(auto it = children.begin(); it != children.end(); it++)
		if((*it)->getName() == name)
		{
			(*it)->setParent( NULL );
			delete (*it);
			children.erase( it );
			break;
		}
}

void Node::addChild(Node* node)
{
	if( children.empty() || node->getZOrder() >= children.back()->getZOrder())
		children.push_back( node );
	else for(auto it = children.begin(); it != children.end(); it++)
		if((*it)->getZOrder() > node->getZOrder())
		{
			children.insert( it, node );
			break;
		}

	node->setParent( this );
}

void Node::removeChild(Node* node, bool cleanup)
{
	children.remove( node );
	node->setParent( NULL );
	if( cleanup )
		delete node;
}

list<Node*> Node::getChildren() const
{
	return children;
}




void Node::runAction(Action* action)
{
	action->setHost( this );
	if( action->host != this ) 
		action->initWithHost( this );
	gDirector->getActionManager()->addAction( action );
}

void Node::runActionWithObject(Object* obj)
{
	Action* action = (Action*) obj;
	runAction( action );
}

void Node::pauseActions()
{
	gDirector->getActionManager()->pauseHost( this );
}

void Node::resumeActions()
{
	gDirector->getActionManager()->resumeHost( this );
}
