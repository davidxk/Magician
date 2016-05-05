A Scheduler maintains a list of functions to run at a specific time point. It is checked upon at the start of each time frame. 

##Scheduled Action: Scheduler or aManager?
A question for scheduler: should scheduled action be managed by a scheduler or action manager? 
The answer to that question is practically decided by the complexity of time system versus action system. 
For example, wouldn't it be strange if a scheduler should host a list of actions to be scheduled? Yet, on the other hand, asking the action manager to acquire time information seems pretty understandable. 

##Elaboration
input: 
* scheduleAt: function, timepoint 
* scheduleAfter: function, period 
* update: timepoint

output: call of functions according to time table
