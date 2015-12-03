#ifndef _IMAGE_LOADER_H_
#define _IMAGE_LOADER_H_

#include <vector>
using namespace std;

//ImageLoader is a static function set
class ImageLoader
{
public:
	//It adds the resources/ path automatically
	static vector<wstring> load(const string& fileName);
	static vector<vector<wstring> > loadBatch(const string& fileName);
};
#endif
