#Updater
##Duty
The duty of this class is to print the new frame to the console. 
caller: TimeManagement
input: new frame
output: cout [80, 24]
algo: print only the changed part

###Thread
It would appear that the Display Central should run in a separate thread. Which has been proven viable. 

###Efficiency
To improve efficiency, I can record every change at the registration center, so that only the changed part would be calculated. But we shouldn't optimize so at such premature stage, should we? 
