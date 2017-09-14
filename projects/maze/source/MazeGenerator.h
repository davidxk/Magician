#ifndef _MAZE_GENERATOR_H_
#define _MAZE_GENERATOR_H_

#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> Cell;

//description of the class here
class MazeGenerator
{
public:
	vector<pair<Cell, Cell> > generate(int rows, int cols);
};
#endif
