#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <exception>
#define DIM 3

struct OutOfMazeException : public std::exception
{
	const char * what() const throw()
	{
		return "The position is out of the maze";
	}
};

struct Position
{
	unsigned int x;
	unsigned int y;
	
	Position(unsigned int x, unsigned int y) : x(x), y(y) { }

	friend std::ostream& operator<<(std::ostream& out, Position& p);
};

class Maze
{
	Position start;
	Position final;
	unsigned int startPos;
	unsigned int finalPos;
	unsigned int maze[3];
public:
	Maze(unsigned xs, unsigned ys, unsigned xf, unsigned yf);	
	virtual ~Maze();
	void PutObstacle(int i, int j);
	bool IsObstacle(int i, int j) const;
	bool IsObstacle(unsigned int p) const;
	bool IsValid(int p) const;
	void SetStartPos(int i, int j);
	void SetStartPos(unsigned int p);
	unsigned int GetStartPos() const;
	unsigned int GetFinalPos() const;
	inline bool IsGoal(unsigned int p) { return p == finalPos; }

	friend std::ostream& operator<<(std::ostream& out, Maze& m);
};

#endif
