#include "basic/ImageLoader.h"
#include <fstream>
#include <iostream>
#include <string>

vector<wstring> ImageLoader::load(const string& fileName)
{
	string path = "../resources/";
	path += fileName;
	wifstream fin(path.c_str());
	if( fin.bad() ) cout<<"Error: File read fail! "<<endl;
	
	wstring line;
	vector<wstring> image;

	while( getline(fin, line) )
		image.push_back( line );
	return image;
}

vector<vector<wstring> > ImageLoader::loadBatch(const string& fileName)
{
	string path = "../resources/";
	path += fileName;
	wifstream fin(path);
	if( fin.bad() ) cout<<"Error: File read fail! "<<endl;

	wstring line;
	vector<wstring> image;
	vector<vector<wstring> > frames;

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
