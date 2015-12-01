

//Sprite is initiated from file by default
class Sprite: public: VisibleObject
{
public:
	Sprite();
	Sprite(const string& fileName);
	bool isInAction;
};
