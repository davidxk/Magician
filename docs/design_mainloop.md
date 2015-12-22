##Main Loop  or  Time Management?
This class was meant to be named Time Management Center for its functionality,
but the name Main Loop makes more sense architecturally, so main loop it is.
But the name Main Loop brings us a question: shouldn't be the functionality of high level controlling be separated from pure time management? That sounds right, but since there really is not much work in the realm of time management at this time, I think I will go with MainLoop = TimeManagement. 
So now Main Loop is the absolute authority in time management. All functions concerning time should be overseen by the Main Loop and should involve the Main Loop. 
But since Main Loop is at a very high level, maybe it is advisable that a Clock class, declared at a low level, controlled by the Main Loop, accessible level globally, should be defined. 

##Implementation Steps
Roll back to the last version of MainLoop. Add Clock to it. Action Manager should refer to the Clock when scheduling. A scheduler should be checked at each update of MainLoop. 

After Scheduler is done, static transition method can be defined and scheduled. 

After that Layer should be introduced for a house to get into view. Snowflakes should be added, too. Smoke animation should be created and success will not to far down the road. 

I think it is safe to assume that boxes won't be a part of this version. Now I can see why people go with bad designs: they simply could not affor the time on it. 
