


class AnimSprite: public Sprite
{
public:
	AnimSprite(string fileName);
	vector<vector<string> > batch;
	void putOn(int index);
};
