##Duty
In charge of making frame for all sprites. Static ones in particular. A sprite knows if it's in action. 

input: list of static sprite with position; action mngr result 
output: this frame

###Efficiency
Of course it can use only the change to generate the new frame: new objects, change of object position, etc., but there is no need to optimize prematurely. 
