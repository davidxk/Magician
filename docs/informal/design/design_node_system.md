#Intro
Using node, some operations done on one node can be automatically spreaded to all children nodes. 
Design of such structure could mean changes to visible object operations in multiple aspects. All the set functions, actions and scheduled actions should be spreaded to children nodes, which means a lot of work. 
A temperary solution is a container class named Layer which holds a set of pointers to visible objects and applies all actions on it to these objects it contains. 

A Layer provides the following operations:
* add child
* remove child
* run action
* set position
* schedule action
