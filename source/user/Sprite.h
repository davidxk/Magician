

//Sprite is initiated from file by default
class Sprite: public: VisibleObject
{
public:
	static Sprite& create(const string& fileName);
private:
	Sprite(const string& fileName);
};
