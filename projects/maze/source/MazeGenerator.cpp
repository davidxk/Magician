#include "MazeGenerator.h"
#include <cstdlib>
#include <stack>
#include <unordered_set>

struct PairIntHash
{
    std::size_t operator()(Cell const& s) const 
    {
        std::size_t h1 = std::hash<int>()(s.first);
        std::size_t h2 = std::hash<int>()(s.second);
        return h1 ^ (h2 << 1);
    }
};

vector<pair<Cell, Cell> > MazeGenerator::generate(int rows, int cols)
{
	Cell start(0, 0);
	stack<Cell> front;
	front.push(start);
	unordered_set<Cell, PairIntHash> visited;
	vector<Cell> dircs;
	dircs.push_back(Cell(0, -1));
	dircs.push_back(Cell(+1, 0));
	dircs.push_back(Cell(0, +1));
	dircs.push_back(Cell(-1, 0));
	vector<pair<Cell, Cell> > result;

	int row, col;
	bool isValid;
	vector<Cell> choices;
	while(not front.empty())
	{
		Cell node = front.top();
		visited.insert(node);
		for(const Cell& dirc: dircs)
		{
			row = node.first + dirc.first;
			col = node.second + dirc.second;
			Cell child(row, col);
			isValid = 0 <= row and row < rows and 0 <= col and col < cols;
			if(visited.find(child) == visited.end() and isValid)
				choices.push_back(child);
		}
		if(choices.empty())
		{
			front.pop();
			continue;
		}
		Cell child = choices[rand() % choices.size()];
		front.push(child);
		result.push_back(pair<Cell, Cell>(node, child));
		choices.clear();
	}
	return result;
}
