#Use Case
##Map Editor
###Use Case: Add Buildings to Map(Keyboard)
User press UP and DOWN to choose from one of the buildings listed in the column on the left of the screen. Press SPACE to select, press again to deselect. When selected, the building appear on the top left corner of the map. It moves as direction keys are pressed. Pressing SPACE releases the building to the map. Pressing SPACE key with the cursor on the building selects it again. When the cursor is in the building column, it only jumps from one building to another. 

> This use case is depreciated, for the operational inconvenience. 

###Use Case: Add Buildings to Map(Mouse)
Use mouse to select one of the buildings from the column on the left of the screen. The building moves with the mouse, with mouse pointing to its center. Clicking releases the building to the map. When the mouse is hovering over a building, it glows. 

> Not sure how control stream, especially mouse, fit into the engine yet. 

###Use Case: Print Map
Print the fixed, visible part of the map to a file. 



##Pokemon-like RPG Game
Basically, it just need to be as good as the original Young Magician game. 

###Use Case: Story Background
Words are printed in the centre of the screen letter by letter, with good line break behaviour. 

###Use Case: Walk
Walk as directional keys are pressed. Collision detection is supported. Positional event triggering is supported. Going indoors is supported. Press ENTER triggers event. Press ESC calls out the game menu. 

###Use Case: Talk to NPC
Press SPACE/ENTER, talk to an NPC. Press RIGHT/DOWN/ENTER/ESC, goes to the next sentence. Press LEFT/UP, goes to the previous sentence. 

###Requirement Description: Bag System
To live in the game world, the character needs items for equipment and consumption. The items are stored in the bag systems. Possession of items can be vital to the survival of the character. Good supply of items means a comfortable life in the game. 

###Requirement Description: Money System
Most items can be bought and sold at shops and stores. A rich man can live a quite enjoyable mortal life in the game world. 

Money can be used to buy a wide range of things, for example a house. Question: what use is a house? A house should be able to serve as a shelter. A player should have full control in his home. There are things that can't be put in your bag and can only be put in a house. 

In Rogue, you can't buy anything, and you have nowhere to stay and rest. In Pokemon, there are cities in between wilderness. You can wonder in the cities and converse with locals after a long travel in the wilderness. It makes the game less intense and more relaxing. Home in Pokemon is useless. You can always restore you strength at Pokemon Centre for free. There is nothing fun in Pokemon Centre which is a waste. One can easily use this sense of safety and design something from it. 

In Rogue, having to think about food is quite a nuisance. But I think it is a good idea, if day time and night time is implemented. 

###Non-functional: Good Design of the Game
It has got a big game map for you to explore. The story is huge and intriguing. There are secrets everywhere on the map, there is just so many, you cannot possibly find all of them. There are monsters that you can easily win and monsters that is hard to beat. You can find genuine sense of improvement as you go level up. 

###Non-functional: Home Sweet Home
I like the feel of a shelter. So one should be able to find everything in a home. To show the sweetness of home, the environment in the wilderness needs to be unwelcoming. 

The rough environment may include the scarce of substance, the danger of being hurt and the lack of human communication. It might be a great field of land with no living thing in your sight. It might be a place with only a narrow path, filled with deadly beasts. It might be a long desert where you have to drink every once in a while to avoid dehydration. Or it could be a snow field where you have to build your igloo to stay for the night. 

###Non-functional: Happiness
Happiness comes from comparison, either with ones own experience or with others' experience. To make happiness, the game must pose certain restrictions to make the player uncomfortable sometimes. 

There could be multiple source of happiness. A keen explorer might find happiness in finding all the hidden areas on the map. A collector might find happiness in completion of his collections. A money man might want to have fun by earning a fortune. A fighter might find happiness in being a experienced worrier. A proud veteran might find happiness in challenging all the mighty monsters. 

###Restrictions and Mortal Happiness
* A bag has a fixed capacity. Money can buy bags of larger capacity
* Man gets hungry as time goes by. A hungry man walks slower and fights weaker. A rich man can buy potions that provides more energy. 
* Foods can be bought from food stores and can be carried in bags. Food can also be stored in a fridge at home. 
* When night comes, a man must find a place to sleep. In the wilderness, a man must build a shelter. In the city, a man needs to stay in a hotel(which could be expensive) or in his house. Failing to sleep in time should have consequences. 