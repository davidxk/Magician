##First-Time Code Reviewing
I must say, what I did was completely amazing. To get all of that shit running without testing, without modern development tools and without any design whatsoever, I would say, is absolutely unbelievable. 

##Project Design
I would say it is a good idea to start new. Start a completely new design. A game engine like a cocos2d-x. 

##Display Subsystem
###Display Central
It holds a 80\*24 console map. At every frame, it updates the map and refreshes the screen. It generates the new frame, compares it with the old one, and prints only the changed part. 

###Visible Object
A Visible Object is to be printed on the console. It knows where to paint itself and how to paint it self as a vector of strings. 

###Sprite
A sprite is a picture. It holds its picture in a string vector. It knows its size and position. A sprite can be subject to an animation action. 

###Box
A Box serves as a interactive item on the console, like a window in Windows. A Box has a rectangular outline. A Box knows its size and position.

###Registration Center
All Visible Object should be registered at the registration center, so that Display Central can print it in the most recent update. For global access, Registration Center should be a global singleton. 


##Time Management Subsystem
###Action
Actions has to be registered at a Action Control center, where the sprite, type of action and duration of the action is taken note of. 

###Time Central
Time Central in charge of managing the time steps and invoking Display Central to update the frame. 
