##Concept of Grouping
A group of visible objects can be treated as one visible object. An operation on the group will be applied to all members of the group. 

Logically, the grouping should be cascading where a group can be listed as the member of another group. 

##Problems
The grouping mechanism may change the contract of Visible Object Manager and Action Manager. Visible Object Manager used to put the objects in a list and the later an object goes into the list, the later it is rendered(the greater its zOrder). 

###Rendering
Now that the Visible Object is managed as a tree, the rendering process would have to change accordingly. 

There are two solutions. Change the rendering function so that it can traverse a tree or add a function that transforms a weighed tree to an ordered list. 

Since Visible Object Manager is still a class with limited responsibilities, I think a traversal rendering function is the better choice. 

####Traversing
At the root of the tree, the rendering function first renders the root of the
tree, then goes to the child with ```lower``` zOrder value, which is to be covered at the back therefore should be rendered . 

####Optimization
Now that there is zOrder and covering, an optimization might be available when there are a lot of images. We could always first calculate the areas that an image will contribute to and then only render this area. In this case, some of the images may be fully covered at the back and therefore should not be included in the rendering process at all. 

#####Rectangle Covering
Two rectangles can have only a few ways of intersecting each other. 
* No intersection
* One eats another whole
* One gets a hole in the middle
* One gets an edge covered
* One gets a corner covered

In the worst case scenario, a rectangle becomes four rectangles - but one can always get a solution in this way. 
