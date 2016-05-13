#ifndef _IMAGE_LOADER_H_
#define _IMAGE_LOADER_H_

#include <string>
#include <vector>
#include "basic/ColoredChar.h"
using namespace std;

//ImageLoader is a static function set
class ImageLoader
{
public:
	//It adds the resources/ path automatically
	static Image load(const string& fileName);
	static vector<Image> loadBatch(const string& fileName);
};
#endif
