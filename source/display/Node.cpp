#include "display/Node.h"
#include "action/ActionManager.h"

void Node::setPos(const Coord cc)
{
	VisibleObject::setPos( cc );

	Coord delta = cc - pos;
	for(auto& child: children)
		child->movePos( delta );
}

void Node::setForeColor(Color foreColor)
{
	VisibleObject::setForeColor( foreColor );
	for(auto& child: children)
		child->setForeColor( foreColor );
}

void Node::setBackColor(Color backColor)
{
	VisibleObject::setBackColor( backColor );
	for(auto& child: children)
		child->setBackColor( backColor );
}

void Node::setColor(Color foreColor, Color backColor)
{
	VisibleObject::setColor( foreColor, backColor );
	for(auto& child: children)
		child->setColor( foreColor, backColor );
}




void Node::movePos(const Coord cc)
{
	pos += cc;
}




void Node::setZOrder(int zOrder)
{
	this->zOrder = zOrder;
}

int Node::getZOrder() const
{
	return zOrder;
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
			children.erase( it );
			(*it)->setParent( NULL );
			break;
		}
}

void Node::addChild(Node* node)
{
	//children.push_back( node );
	for(auto it = children.begin(); it != children.end(); it++)
		if((*it)->getZOrder() > node->getZOrder())
			children.insert( it, node );
	node->setParent( this );
}

void Node::removeChild(Node* node)
{
	children.remove( node );
	node->setParent( NULL );
}

list<Node*> Node::getChildren() const
{
	return children;
}

void Node::setParent(Node* node)
{
	this->parent = node;
}

Node* Node::getParent() const
{
	return parent;
}




void Node::runAction(Action* action)
{
	action->setHost( this );
	if( action->host != this ) 
		action->initWithHost( this );
	aManager->addAction( action );
}

void Node::runActionWithObject(Object* obj)
{
	Action* action = (Action*) obj;
	runAction( action );
}

void Node::pauseActions()
{
	aManager->pauseHost( this );
}

void Node::resumeActions()
{
	aManager->resumeHost( this );
}
