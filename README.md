# Magician
Magician is a text-based game engine that supports both Mac and Windows. 

<!-- a image -->

# Getting Start with Magician
```cpp
// A simple Hello World game project with Magician

class HelloWorld: public Scene
{
public:
	virtual void initScene() override
	{
		// Create a sprite
		Sprite* image = Sprite::create("image.txt");

		// Define position for the sprite
		const int num39 = ConsoleCoord::MAX_COLUMN / 2;
		const int num11 = ConsoleCoord::MAX_LINES / 2;
		image->setCenterPos( Coord(num11, num39) );

		// Add the sprite to the scene
		this->addChild( image );
	}
};

int main()
{
	// Create a scene
	Scene* hello = new HelloWorld();

	// Engine run with the scene
	gMainLoop->runWithScene( hello );
	
	return 0;
}
```

## Classes
| class | description |
|-------|-------------|
 Sprite | an image to be shown in the game scene
 Scene  | game scene, initiates the elements of the scene
 Action | base class of a collection of action class

## Actions
| class | description |
|-------|-------------|
Animation | make an animation out of animation frames
CallFunc | function call wrapped as an action
Jump    | jump action
MoveBy  | move sprite by a given vector
MoveTo  | move sprite to a given coordinate
Repeat  | repeat an action for some given time
Sequence| put actions in a sequence
Sleep   | pause for some given time
Vanish  | make sprite vanish instantly
Appear  | make sprite appear instantly

