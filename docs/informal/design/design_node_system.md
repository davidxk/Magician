#Intro
Using node, some operations done on one node can be automatically spread to all children nodes. 
Design of such structure could mean changes to visible object operations in multiple aspects. All the set functions, actions and scheduled actions should be spread to children nodes, which means a lot of work. 
A temporary solution is a container class named Layer which holds a set of pointers to visible objects and applies all actions on it to these objects it contains. 

A Layer provides the following operations:
* add child
* remove child
* run action
* set position
* schedule action

#Memory Management
Memory Management is useful because there is absolutely no way to know if a pointer has been freed. So I might want to try smart pointer in the future. 
