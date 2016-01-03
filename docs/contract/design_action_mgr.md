##Duty
> Updates attributes for all objects in action. 

* caller: MainLoop
* duties: update object attributes
* provdr: user program
* inpute: action 
* client: VisibleObjManager
* output: objects with attributes updated

###Elaboration
A Action Manager manages actions. Each action knows its host sprite. The actions generates the update command when initiated and puts it in a queue. The Action Manager holds a list (literally, linked list which works well for random removal) of all actions' command queues. When a command queue is empty, its hosting action will be removed from the list. 

###Future
The list will maintained incremental in zOrder. 
