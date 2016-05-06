#Subsystems
##Audio

##Display
######addToManager()
addToManager() is a temporary solution until the node system is implemented. The full function of the node system is as of 2016-05-06 yet to be defined. 

######zOrder
zOrder is as of 2016-05-06 yet to be implemented. 

######ColoredChar
It appears both windows and unix require a unsigned short to store color info. 

##Action
######Implementation
Actions are implemented as a queue of commands that alters the attributes of visible objects. 

######Sequence and Repeat
Both are implemented as a longer sequence of Commands. Sequence is the concatenation of Command queues. Repeat for finite times is implemented as the repetition of a Command queue; repeat for infinite times is implemented as a cyclic queue.

######runAction()
runAction() method is implenmented in class VisibleObject. 

##Scheduler
######Functions With Arguments
Scheduler for functions with arguments is yet to be implemented. 
##Sprite

##Data

