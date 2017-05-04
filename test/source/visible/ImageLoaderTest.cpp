#include "visible/ImageLoaderTest.h"
#include <cassert>
#include "visible/ImageLoader.h"

void ImageLoaderTest::run()
{
	testLoad();
	testLoadBatch();
}

void ImageLoaderTest::testLoad()
{
	//load image
	Image image = ImageLoader::load("graph/moon.txt");
	assert( image.size() == 2 );
	assert( ImageUtil::ImageLine2str( image[0] ) == "1234" &&
			ImageUtil::ImageLine2str( image[1] ) == "4321" );
}

void ImageLoaderTest::testLoadBatch()
{
	//load animation batch
	vector<Image> batch = ImageLoader::
		loadBatch("batch/moon_batch.txt");
	assert( batch.size() == 3 );
	assert( batch[0].size()==1 && batch[1].size()==1 && batch[2].size()==1);
	assert( ImageUtil::ImageLine2str( batch[0][0] ) == "1234" &&
			ImageUtil::ImageLine2str( batch[1][0] ) == "4444" &&
			ImageUtil::ImageLine2str( batch[2][0] ) == "4321" );
}
