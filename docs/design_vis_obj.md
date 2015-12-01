##Intro
A Visible Object is a base class that is inherited by all of the printed items on the console. Examples are sprite and boxes. 

A Visible Object is always rectangular in shape, but it may contain transparent areas, which will be marked with a special character. It may be a good idea if the character is unprintable. 

The rectangular shape is guaranteed by asserting all strings in the vector should have the same length. 

Different Visible Object may be initiated in different ways. A image may be read from a file while a box's outline and content is filled by the program. 
