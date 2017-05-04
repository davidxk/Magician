#ifndef _IMAGE_LOADER_TEST_H_
#define _IMAGE_LOADER_TEST_H_

#include "TestCase.h"

//description of the class here
class ImageLoaderTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Image Loader Test"; }
private:
	void testLoad();
	void testLoadBatch();
};
#endif
