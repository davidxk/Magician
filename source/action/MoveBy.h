#ifndef _MOVE_BY_H_
#define _MOVE_BY_H_

#include "action/Command.h"
#include "action/MoveTo.h"

//MoveBy action moves a sprite by a specified vector
class MoveBy: public Action
{
public:
	MoveBy(Node* host, int duration, Coord aVect);
	virtual Action* clone() const override;
	static MoveBy* create(Node* host, int duration, Coord aVect);
	static MoveBy* create(int duration, Coord aVect);
	virtual void getCmdQueue() override;
private:
	Coord vect;
};



//MoveByCommand modifies a sprites position by a certain vector
class MoveByCommand: public Command
{
public:
	MoveByCommand(Coord aBy);
	virtual Command* clone() { return new MoveByCommand(*this); }
	virtual void apply(Node* vo);
private:
	Coord by;
};
#endif
