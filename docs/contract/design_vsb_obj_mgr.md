##Duty
> Renders the current frame with visible objects. 

* caller: MainLoop
* duties: render frames
* provdr: user program
* inpute: ojbects to show
* client: DisplayCentral
* output: [24, 80] frame
* algori: print the part in the screen


###Quote
> All things to be displayed on the screen should register with vManager. 

###Efficiency
To improve efficiency, I can record every change, and obtain the new frame from the change record and the last frame. 
