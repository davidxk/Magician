#Subsystems
##Audio
> * Class Diagram

A simple music player for Windows. Provides the service of playing music on a seperate thread. 

##Display
* Class Diagram

Provides visible object display service. Holds a list of visible objects, and in every update turn them into a frame and print it. 

##Action
* Class Diagram

Provides a series of actions for users. Each action is a queue of command that alters visible object attributes. Action manager applies these changes to the visible object in each main loop update. 

##Scheduler
* Class Diagram

Provides delayed calling service of functions. 

##Sprite
* Class Diagram

Provides a series of visible objects meant for specific purposes. 

##Data
* Class Diagram

Provides data classes that are used in many other subsystems. 
