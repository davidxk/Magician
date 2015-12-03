##Duty
In charge of making frame for all sprites in action. 

input: Sprite, action type, duration; time now
output: image with size and position 

###Elaboration
A Action Manager manages actions. Each action knows its host sprite. The actions generates the update command from the sprite and puts it in a queue. The Action Manager holds a list (literally, linked list which works well for random removal) of all actions and pops one frame from the head at every time step. When a queue is empty, the action is removed from the list. The list is maintained incremental in zOrder. 

Since there is polymorphic behaviour is required, the actions has to be created in the heap area. 
