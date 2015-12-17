#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ImageProcessor
{
public:
	vector<string> start(const vector<string>& image);
private:
	int leftMargin(const string& line);
};

int ImageProcessor::leftMargin(const string& line)
{
	for(int i=0; i<line.size(); i++)
		if( line[i]!=' ')
			return i;
}

vector<string> ImageProcessor::start(const vector<string>& image)
{
	int minMargin = leftMargin( image[0] );
	int maxLength = 0;
	for(const auto& line: image)
	{
		int margin = leftMargin( line );
		if( minMargin>margin )
			minMargin = margin;
		if( maxLength<line.size() )
			maxLength = line.size();
	}
	int length = maxLength - minMargin;

	vector<string> processed;
	for(const auto& line: image)
	{
		int actualLen = line.size() - minMargin;
		int rightMargin = length - actualLen;
		string spaces(rightMargin, ' ');
		string right;
		if( line.size()<minMargin ) right = line;
		else right = line.substr( minMargin, actualLen );
		processed.push_back( right + spaces );
	}
	return processed;
}

int main()
{
	string line;
	vector<string> image;
	while( getline(cin, line) )
		if (!line.empty()) 
			image.push_back( line );

	ImageProcessor ip;
	vector<string> processed = ip.start( image );
	for(const auto& line: processed)
		cout<<line<<endl;
	return 0;
}
