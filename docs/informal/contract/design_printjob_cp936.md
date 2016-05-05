>This design is not to be implemented, since the previous PrintJob design can perfectly Print the wider chars. The design, however, will be kept for future reference. 

##Contract
###PrintJob
* PrintJob combines position with colored strings. 
* A PrintJob is a stream of chars to be printed that are consecutive in space and color. 

###DisplayCentral
* DisplayCentral is responsible for the production of such PrintJobs

###Printer
* Printer is responsible for printing the PrintJobs in reasonable manners
