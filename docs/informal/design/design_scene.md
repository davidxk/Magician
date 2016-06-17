#Intro
Scenes are defined for modelling different stage scenes. Scenes are made of settings and the basic operation for a scene is change scene. 
A scene class works by filling the scene(managers) with visible, interactive elements. It does so when called upon at the start of a scene by the MainLoop. 

What if each scene hosts its own managers? MainLoop simply use the managers of the running scene. Then multiple scenes could reside in the memory at the same time. 
This is a very bold move, but it makes perfect sense. 

* caller: MainLoop
* duties: define visible objects
* client: UserProgram
