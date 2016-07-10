#include "action/Jump.h"
#include <cassert>
#include <cmath>
#include <queue>
#include <stack>
#include "action/MoveBy.h"
#include "basic/TimeService.h"

#include <iostream>
using namespace std;
Jump::Jump(Node* host, int duration): Action(host, duration) { }

Jump* Jump::create(Node* host, int tall, float heightOverTall)
{
	assert( tall != 0 );
	float gg = 35.5 * 0.000001 * tall;
	float hh = heightOverTall * tall;
	float tt = pow(2 * hh / gg, 0.5);
	float vv = pow(2 * hh * gg, 0.5);
	Jump* jump = new Jump(host, tt * 2);
	jump->setAttributes(gg, hh, tt, vv);
	jump->getCmdQueue();
	return jump;
}

void Jump::setAttributes(float gg, float hh, float tt, float vv)
{
	// gg as in unit/ms^2
	// hh as in unit
	// tt as in ms
	// vv as in unit/ms
	this->gg = gg, this->hh = hh, this->tt = tt, this->vv = vv;
}

void Jump::getCmdQueue()
{
	int lastHeight = 0, leftEnd = 0, rightEnd = 0;
	findHoverSegment(leftEnd, rightEnd);
	int end = round( leftEnd + 0.45 * (rightEnd - leftEnd) ); // shortened 

	queue<Command*> que;
	stack<Command*> stk;
	for(int i = 0; i < end; i++)
	{
		int time = i * TimeService::TIME_UNIT;
		float real_height = vv * time - 0.5 * gg * time * time;
		int height = round( real_height );

		if(height - lastHeight > 0)
		{
			que.push( new MoveByCommand( Coord(lastHeight - height, 0) ) );
			stk.push( new MoveByCommand( Coord(height - lastHeight, 0) ) );
			lastHeight = height;
		}
		else 
		{
			que.push( new Command() );
			stk.push( new Command() );
		}
	}
	while( !que.empty() )
	{
		cmdQueue.push( que.front() );
		que.pop();
	}
	while( !stk.empty() )
	{
		cmdQueue.push( stk.top() );
		stk.pop();
	}
}

void Jump::findHoverSegment(int& leftEnd, int& rightEnd)
{
	int steps = tt * 2 / TimeService::TIME_UNIT;
	int lastHeight = 0; 

	for(int i=0; i<=steps; i++)
	{
		int time = i * TimeService::TIME_UNIT;
		float real_height = vv * time - 0.5 * gg * time * time;
		int height = round( real_height );

		if(height - lastHeight > 0)
		{
			lastHeight = height;
			leftEnd = i;
		}
		else if(height - lastHeight < 0)
		{
			rightEnd = i;
			break;
		}
	}
}
