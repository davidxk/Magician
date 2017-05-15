#include "MazeGenerator.h"
#include <cstdlib>

vector<vector<int> > MazeGenerator::generate(int row, int col)
{
	vector<vector<int> > maze(row, vector<int>(col, -1));
	for(auto& line: maze)
		for(auto& elem: line)
			elem = rand() % 2;
	return maze;
}
