#include "basic/ImageLoader.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include "basic/MagicianMacros.h"

Image ImageLoader::load(const string& fileName)
{
	string path = magician::RES_PATH;
	path += fileName;
	ifstream fin(path.c_str());
	if( fin.bad() ) cout<<"Error: File read fail! "<<endl;
	
	string line;
	Image image;

	while( getline(fin, line) )
		image.push_back( ImageUtil::str2ImageLine( line ) );
	assert( image.size() );
	return image;
}

vector<Image> ImageLoader::loadBatch(const string& fileName)
{
	string path = magician::RES_PATH;
	path += fileName;
	ifstream fin(path);
	if( fin.bad() ) cout<<"Error: File read fail! "<<endl;

	string line;
	Image image;
	vector<Image> frames;

	int nFrame = 0, nLine = 0;
	fin>>nFrame>>nLine; fin.get();
	for(int i=0; i<nFrame; i++)
	{
		for(int j=0; j<nLine; j++)
		{
			getline(fin, line);
			image.push_back( ImageUtil::str2ImageLine( line ) );
		}
		frames.push_back( image );
		image.clear();
	}
	return frames;
}
