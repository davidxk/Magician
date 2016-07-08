#ifndef _JUMP_H_
#define _JUMP_H_

#include "action/Action.h"
#include "display/Node.h"

//description of the class here
class Jump: public Action
{
public:
	static Jump* create(Node* host, int tall, float heightOverTall);
	void setAttributes(float gg, float hh, float tt, float vv);
	void getCmdQueue();
	void findHoverSegment(int& leftEnd, int& rightEnd);
private:
	Jump(Node* host, int duration);
	float gg, hh, tt, vv;
};
#endif
