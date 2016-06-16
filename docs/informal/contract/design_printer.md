##Duty
> Print a character with attributes as specified in its emclosing PrintJob

* caller: DisplayCentral
* duties: print a PrintJob
* provdr: DisplayCentral
* inpute: PrintJob
* output: char printed

###Elaboration
####Inheritance
Printer base-class defines a common interface for printer sub-class of each platform. 

####Makefile
Building the project on different platform requires different source files, thus makefile should specify this difference in file listing. 

The technique for this split is yet to be learnt. 
