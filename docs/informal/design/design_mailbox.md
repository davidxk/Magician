Mailbox may not be in the final design, but it is a viable way for the two threads(Mainloop and User thread) to communicate. 

Since transition heavily depends on the collaboration of Mainloop and initialization of the next scene, it might be a good idea to 

A simpler implementation is to have the user code release the two managers on a schedule. Thus a functional action is needed. 
