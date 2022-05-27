#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sys/resource.h>

#include "Board.hh"

int main() 
{
	//unsigned int brdSize = 3;
	Board board(3);
	char **newBrd = new char *[3];
	for(size_t i = 0; i < 3; ++i)
	{
		newBrd[i] = new char[3];
	}
	newBrd[0][0] = 'x';
	newBrd[0][1] = 'x';
	newBrd[0][2] = 'x';
	newBrd[1][0] = 'o';
	newBrd[1][1] = 'x';
	newBrd[1][2] = 'o';
	newBrd[2][0] = 'x';
	newBrd[2][1] = 'x';
	newBrd[2][2] = 'x';
	
	board.setBoard(newBrd, 3);
	std::cout<<board.rowWin(0) <<std::endl;
}