A Scheduler maintains a list of functions to run at a specific time point. It is checked upon at the start of each time frame. 

##Scheduled Action: Scheduler or aManager?
Q: Should scheduled action be managed by a scheduler or action manager? 
A: It should go with the scheduler by scheduling the runAction() function as follows:
	auto scheduledAction = std::bind(&Sprite::runAction, snowSprite);
	gScheduler->scheduleAfter( scheduledAction, stdDure );

##Elaboration
input: 
* scheduleAt: function, timepoint 
* scheduleAfter: function, period 
* update: timepoint

output: call of functions according to time table
