#include "Maze.hpp"
#include <iostream>

Maze::Maze(unsigned xs, unsigned ys, unsigned xf, unsigned yf) : start(xs, ys),
																 final(xf, yf)
{
	startPos = (xs << 3) + xs + ys;
	finalPos = (xf << 3) + xf + yf;

	if (startPos >= 81 || finalPos >= 81) {
		throw OutOfMazeException(); 
	}

	for(int i = 0; i < 3; ++i) {
		this -> maze[i] = 0x00000000;
	}
}

Maze::~Maze()
{
}

void Maze::PutObstacle(int i, int j)
{
	int pos = (i << 3) + i + j;

	if (pos >= 81 || pos == startPos || pos == finalPos) {
		throw OutOfMazeException(); 
	}

	maze[2 - (pos >> 5)] |= (1 << (pos % 32));
}

bool Maze::IsObstacle(int i, int j) const
{
	int pos = (i << 3) + i + j;

	if (pos >= 81) {
		throw OutOfMazeException(); 
	}

	return (maze[2 - (pos >> 5)] & (1 << (pos % 32)));
}

bool Maze::IsObstacle(unsigned int p) const
{
	if(p >= 81) {
		throw OutOfMazeException(); 
	}
	
	return (maze[2 - (p >> 5)] & (1 << (p % 32)));
}

bool Maze::IsValid(int p) const
{
	if(p >= 81 || p < 0) {
		return false;
	}

	return !((maze[2 - (p / 32)] & (1 << (p % 32))));
}

void Maze::SetStartPos(int x, int y)
{
	this -> start . x = x;
	this -> start . y = y;
	this -> startPos = (x << 3) + x + y;
}

void Maze::SetStartPos(unsigned int p)
{
	this -> startPos = p;
	this -> start . x = p / 9;
	this -> start . y = p % 9;
}

unsigned int Maze::GetStartPos() const
{
	return this -> startPos;
}

unsigned int Maze::GetFinalPos() const
{
	return this -> startPos;
}

std::ostream& operator<<(std::ostream& out, Maze& m)
{
	unsigned int k = 0x00000001;

	for(int i = 0; i < 81; ++i) { 
		out << '|';
		if (i == m.startPos) {
			out << '@';
		}
		else if (i == m.finalPos) {
			out << '$';
		} else if((m.maze[2 - (i >> 5)] & k) == 0X00000000) {
			out << '_';
		} else {
			out << 'X';
    	}
		if (i % 9 == 8) {
			out << '|' << std::endl;
		}
		k = k << 1;
		k == 0x00000000 ? k = 0x00000001 : k = k;
	}
	return out;	
}

std::ostream& operator<<(std::ostream& out, Position& p)
{
	out << p.x << " " << p.y << std::endl;	
	return out;
}
