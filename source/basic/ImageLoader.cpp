#include "basic/ImageLoader.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include "basic/MagicianMacros.h"

vector<string> ImageLoader::load(const string& fileName)
{
	string path = magician::RES_PATH;
	path += fileName;
	ifstream fin(path.c_str());
	if( fin.bad() ) cout<<"Error: File read fail! "<<endl;
	
	string line;
	vector<string> image;

	while( getline(fin, line) )
		image.push_back( line );
	assert( image.size() );
	return image;
}

vector<vector<string> > ImageLoader::loadBatch(const string& fileName)
{
	string path = magician::RES_PATH;
	path += fileName;
	ifstream fin(path);
	if( fin.bad() ) cout<<"Error: File read fail! "<<endl;

	string line;
	vector<string> image;
	vector<vector<string> > frames;

	int nFrame = 0, nLine = 0;
	fin>>nFrame>>nLine; fin.get();
	for(int i=0; i<nFrame; i++)
	{
		for(int j=0; j<nLine; j++)
		{
			getline(fin, line);
			image.push_back( line );
		}
		frames.push_back( image );
		image.clear();
	}
	return frames;
}
