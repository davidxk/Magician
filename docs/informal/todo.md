+ makefile compatibility with mac
+ Mainloop replace scene function
+ Make Mainloop a global singleton
+ design scene class
+ rewrite HelloWorld scene
+ repair "object add fail"
+ repair "action fail"
+ design layer system
+ design object base class
+ Printer->print(list<PrintJob>)
+ No user thread needed
+ KeyDispatcher implementation
+ rewrite tests
+ node system
+ time service pause support
- each scene with its own managers
- delete MainLoop class
- count down Repeat
- mover cursor
- test Wait
- time service rename
- transparent color
- design class Frame
- Window system design
- add feature zOrder
- scroll unfold animation

#Makefile compatibility
* add makewin directory with win.mk adding WinPrinter to $(sources)
