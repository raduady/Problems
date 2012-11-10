#include "Maze.hpp"
#include <queue>

#define MDIM 81

inline void Set(unsigned int closed[3], int p)
{
	closed[2 - (p >> 5)] |= (1 << (p % 32));
}

inline bool Contains(unsigned int closed[3], int p)
{
	return (closed[2 - (p >> 5)] & (1 << (p % 32)));
}

void BFS(Maze& maze)
{
	std::queue<int> frontier;
	int parent[MDIM];
	int cPos, nPos;
	unsigned int closed[3];
	unsigned int found[3];
	
	for(int i = 0; i < 3; ++i) {
		closed[i] = 0x00000000;
		found[i] = 0x00000000;
	}
	cPos = maze . GetStartPos();
	frontier.push(cPos);
	parent[cPos] = -1;

	while(!frontier.empty()) {
		cPos = frontier.front();
		frontier.pop();
		if(maze . IsGoal(cPos)) {
			break;
		}

		nPos = cPos - 1;
		if (cPos % 9 != 0) {
			if (maze.IsValid(nPos) &&
				!Contains(closed, nPos) &&
				!Contains(found, nPos)) {
				frontier.push(nPos);
				Set(found, nPos);
				parent[nPos] = cPos;
			}
		}
		nPos = cPos + 1;
		if (cPos % 9 != 8) {
			if (maze.IsValid(nPos) &&
				!Contains(closed, nPos) &&
				!Contains(found, nPos)) {
				frontier.push(nPos);
				Set(found, nPos);
				parent[nPos] = cPos;
			}
		}
		nPos = cPos - 9;
		if (maze.IsValid(nPos) &&
			!Contains(closed, nPos) &&
			!Contains(found, nPos)) {
			frontier.push(nPos);
			Set(found, nPos);
			parent[nPos] = cPos;
		}
		nPos = cPos + 9;
		if (maze.IsValid(nPos) &&
			!Contains(closed, nPos) &&
			!Contains(found, nPos)) {
			frontier.push(nPos);
			Set(found, nPos);
			parent[nPos] = cPos;
		}

		Set(closed, cPos);
	}
	
	while(parent[cPos] >= 0) {
		cPos = parent[cPos];
		maze . SetStartPos(cPos);
		std::cout << maze;
	}
}

int main(void)
{
	Maze maze(4, 5, 5, 5);

	BFS(maze);	

	return 0;
}
