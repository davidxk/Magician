#include "Maze.h"

vector<vector<int> > Maze::makeMazeMap(const vector<pair<Cell, Cell> >& ways, int rows, int cols)
{
	vector<vector<int> > mazeMap;
	for(int i = 0; i < 2 * rows + 1; i++)
		mazeMap.push_back(vector<int>(2 * cols + 1, 1));
	for(const pair<Cell, Cell>& way: ways)
	{
		Cell coordA = way.first, coordB = way.second;
		Cell posWay(coordA.first + coordB.first + 1,
				coordA.second + coordB.second + 1);
		mazeMap[coordA.first * 2 + 1][coordA.second * 2 + 1] = 0;
		mazeMap[coordB.first * 2 + 1][coordB.second * 2 + 1] = 0;
		mazeMap[posWay.first][posWay.second] = 0;
	}
	return mazeMap;
}

Image Maze::makeMazeImage(const vector<vector<int> >& mazeMap)
{
	Image img; 
	for(int i = 0; i < mazeMap.size(); i++)
	{
		img.push_back(ImageLine());
		for(int j = 0; j < mazeMap[i].size(); j++)
			switch(mazeMap[i][j])
			{
				case 0: img[i].push_back(ColoredChar(' ')); break;
				case 1: img[i].push_back(ColoredChar('#')); break;
				default: break;
			}
	}
	return img;
}
