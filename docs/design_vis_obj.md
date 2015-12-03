##Intro
A Visible Object is a base class that is inherited by all of the printed items on the console. Examples are sprite and boxes. 

A Visible Object is always rectangular in shape, but it may contain transparent areas, which will be marked with a special character. It may be a good idea if the character is unprintable. 

The rectangular shape is guaranteed by asserting all strings in the vector should have the same length. 

Different Visible Object may be initiated in different ways. A image may be read from a file while a box's outline and content is filled by the program. 

##UTF-8 Trouble
Apparently you just replace string with wstring, char with wchar_t and it's done. Over too easy. 

##Decision
Now a decision must be made between string and wstring.
string: byte-wise operation
wstring: character-wise operation
Two problems we care about are: printing length and inter-character pollution
Neither can guarantee the printed length since the printing attribute heavily relies on the terminal that it runs on, so the first concern can't be properly addressed. 
On the second issue, wstring clearly does better than string. So the logical solution is to redefine print job and printer: by printing all the rest of the line starting from the diff point. In this way, the characters won't be polluted and the printing job is minimized. 
A better solution perhaps is to match from both sides and only print the middle part, where the main character resides. 
But a bigger problem arise when considering the frame making process. There is absolutely no way to guarantee that the frame is 80\*24 in print space. So all in all, perhaps the safest solution for now is to guarantee that all character is ascii or at least, one space in printing. 

With all of the above said, unless there is compatibility problem with wstring, it is clearly a better choice than string. So wstring it is. 
