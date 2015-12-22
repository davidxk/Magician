##Duty
In charge of updating attributes for all sprites in action. 

input: Sprite, action 
output: Sprite with new attributes

###Elaboration
A Action Manager manages actions. Each action knows its host sprite. The actions generates the update command from the sprite and puts it in a queue. The Action Manager holds a list (literally, linked list which works well for random removal) of all actions' command queues. When a queue is empty, the action is removed from the list. 

The list will maintained incremental in zOrder. 

Since there is polymorphic behaviour is required, the actions has to be created in the heap area. 
