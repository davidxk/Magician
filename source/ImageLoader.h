

//ImageLoader is a static function set
class ImageLoader
{
public:
	//It adds the resources/ path automatically
	static vector<string> load(const string& fileName);
	static vector<vector<string> > loadBatch(const string& fileName);
};
