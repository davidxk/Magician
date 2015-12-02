#include "ImageLoader.h"
#include <fstream>
#include <string>

vector<string> ImageLoader::load(const string& fileName)
{
	ifstream fin(fileName);
	string line;
	vector<string> image;

	while( getline(fin, line) )
		image.push_back( line );
}

vector<vector<string> > ImageLoader::loadBatch(const string& fileName)
{
	ifstream fin(fileName);
	string line;
	vector<string> image;
	vector<vector<string> > frames;

	int nFrame, nLine;
	fin>>nFrame>>nLine; fin.get();
	for(int i=0; i<nFrame; i++)
	{
		for(int j=0; j<nLine; j++)
		{
			getline(fin, line);
			image.push_back( line );
		}
		frames.push_back( image );
	}
	return frames;
}
