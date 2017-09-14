#ifndef _MAZE_H_
#define _MAZE_H_

#include "MazeGenerator.h"
#include "Magician.h"
#include <vector>

//description of the class here
class Maze
{
public:
	static vector<vector<int> > makeMazeMap(const vector<pair<Cell, Cell> >& ways,
			int rows, int cols);
	static Image makeMazeImage(const vector<vector<int> >& mazeMap);
};
#endif
