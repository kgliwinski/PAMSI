#include "doctest/doctest.h"
#include "../include/Board.hh"

TEST_CASE("rowWin #1")
{
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
	newBrd[2][0] = '_';
	newBrd[2][1] = 'x';
	newBrd[2][2] = 'x';
	board.setBoard(newBrd, 9);
	CHECK(board.rowWin(0) == playerW);
    CHECK(board.rowWin(1) == noWin);
    CHECK(board.rowWin(2) == noWin);
	CHECK(board.evaluate() == playerW);
}

TEST_CASE("rowWin #2")
{
    Board board(3);
	char **newBrd = new char *[3];
	for(size_t i = 0; i < 3; ++i)
	{
		newBrd[i] = new char[3];
	}
	newBrd[0][0] = 'x';
	newBrd[0][1] = 'o';
	newBrd[0][2] = 'x';
	newBrd[1][0] = 'x';
	newBrd[1][1] = 'x';
	newBrd[1][2] = 'x';
	newBrd[2][0] = '_';
	newBrd[2][1] = 'x';
	newBrd[2][2] = 'x';
	board.setBoard(newBrd, 9);
	CHECK(board.rowWin(0) == noWin);
    CHECK(board.rowWin(1) == playerW);
    CHECK(board.rowWin(2) == noWin);
	CHECK(board.evaluate() == playerW);
}

TEST_CASE("rowWin #3")
{
    Board board(3);
	char **newBrd = new char *[3];
	for(size_t i = 0; i < 3; ++i)
	{
		newBrd[i] = new char[3];
	}
	newBrd[0][0] = 'x';
	newBrd[0][1] = 'o';
	newBrd[0][2] = 'x';
	newBrd[1][0] = 'x';
	newBrd[1][1] = 'o';
	newBrd[1][2] = 'x';
	newBrd[2][0] = 'x';
	newBrd[2][1] = 'x';
	newBrd[2][2] = 'x';
	board.setBoard(newBrd, 9);
	CHECK(board.rowWin(0) == noWin);
    CHECK(board.rowWin(1) == noWin);
    CHECK(board.rowWin(2) == playerW);
	CHECK(board.evaluate() == playerW);
}

TEST_CASE("rowWin #4")
{
    Board board(3);
	char **newBrd = new char *[3];
	for(size_t i = 0; i < 3; ++i)
	{
		newBrd[i] = new char[3];
	}
	newBrd[0][0] = 'x';
	newBrd[0][1] = 'o';
	newBrd[0][2] = '_';
	newBrd[1][0] = 'x';
	newBrd[1][1] = 'o';
	newBrd[1][2] = '_';
	newBrd[2][0] = '_';
	newBrd[2][1] = 'x';
	newBrd[2][2] = '_';
	board.setBoard(newBrd, 9);
	CHECK(board.rowWin(0) == noWin);
    CHECK(board.rowWin(1) == noWin);
    CHECK(board.rowWin(2) == noWin);
	CHECK(board.evaluate() == noWin);
}

TEST_CASE("colWin #1")
{
    Board board(3);
	char **newBrd = new char *[3];
	for(size_t i = 0; i < 3; ++i)
	{
		newBrd[i] = new char[3];
	}
	newBrd[0][0] = 'x';
	newBrd[0][1] = 'x';
	newBrd[0][2] = 'o';
	newBrd[1][0] = 'x';
	newBrd[1][1] = 'x';
	newBrd[1][2] = 'o';
	newBrd[2][0] = 'x';
	newBrd[2][1] = 'o';
	newBrd[2][2] = 'x';
	board.setBoard(newBrd, 9);
	CHECK(board.colWin(0) == playerW);
    CHECK(board.colWin(1) == noWin);
    CHECK(board.colWin(2) == noWin);
	CHECK(board.evaluate() == playerW);
}

TEST_CASE("colWin #2")
{
    Board board(3);
	char **newBrd = new char *[3];
	for(size_t i = 0; i < 3; ++i)
	{
		newBrd[i] = new char[3];
	}
	newBrd[0][0] = 'x';
	newBrd[0][1] = 'o';
	newBrd[0][2] = 'x';
	newBrd[1][0] = 'x';
	newBrd[1][1] = 'o';
	newBrd[1][2] = '_';
	newBrd[2][0] = '_';
	newBrd[2][1] = 'o';
	newBrd[2][2] = 'x';
	board.setBoard(newBrd, 9);
	CHECK(board.colWin(0) == noWin);
    CHECK(board.colWin(1) == opponentW);
    CHECK(board.colWin(2) == noWin);
	CHECK(board.evaluate() == opponentW);
}

TEST_CASE("colWin #3")
{
    Board board(3);
	char **newBrd = new char *[3];
	for(size_t i = 0; i < 3; ++i)
	{
		newBrd[i] = new char[3];
	}
	newBrd[0][0] = 'x';
	newBrd[0][1] = 'o';
	newBrd[0][2] = 'x';
	newBrd[1][0] = 'x';
	newBrd[1][1] = 'o';
	newBrd[1][2] = 'x';
	newBrd[2][0] = 'o';
	newBrd[2][1] = 'x';
	newBrd[2][2] = 'x';
	board.setBoard(newBrd, 9);
	CHECK(board.colWin(0) == noWin);
    CHECK(board.colWin(1) == noWin);
    CHECK(board.colWin(2) == playerW);
	CHECK(board.evaluate() == playerW);
}

TEST_CASE("colWin #4")
{
    Board board(3);
	char **newBrd = new char *[3];
	for(size_t i = 0; i < 3; ++i)
	{
		newBrd[i] = new char[3];
	}
	newBrd[0][0] = 'x';
	newBrd[0][1] = 'o';
	newBrd[0][2] = '_';
	newBrd[1][0] = '_';
	newBrd[1][1] = 'o';
	newBrd[1][2] = 'x';
	newBrd[2][0] = 'x';
	newBrd[2][1] = '_';
	newBrd[2][2] = 'x';
	board.setBoard(newBrd, 9);
	CHECK(board.colWin(0) == noWin);
    CHECK(board.colWin(1) == noWin);
    CHECK(board.colWin(2) == noWin);
	CHECK(board.evaluate() == noWin);
}

TEST_CASE("diagLeftWin")
{
    Board board(3);
	char **newBrd = new char *[3];
	for(size_t i = 0; i < 3; ++i)
	{
		newBrd[i] = new char[3];
	}
	newBrd[0][0] = 'x';
	newBrd[0][1] = 'o';
	newBrd[0][2] = '_';
	newBrd[1][0] = '_';
	newBrd[1][1] = 'x';
	newBrd[1][2] = 'o';
	newBrd[2][0] = 'x';
	newBrd[2][1] = '_';
	newBrd[2][2] = 'x';
	board.setBoard(newBrd, 9);
    CHECK(board.diagLeftWin() == playerW);
	CHECK(board.evaluate() == playerW);
}

TEST_CASE("diagRightWin")
{
    Board board(3);
	char **newBrd = new char *[3];
	for(size_t i = 0; i < 3; ++i)
	{
		newBrd[i] = new char[3];
	}
	newBrd[0][0] = 'o';
	newBrd[0][1] = 'o';
	newBrd[0][2] = 'x';
	newBrd[1][0] = '_';
	newBrd[1][1] = 'x';
	newBrd[1][2] = 'o';
	newBrd[2][0] = 'x';
	newBrd[2][1] = '_';
	newBrd[2][2] = '_';
	board.setBoard(newBrd, 9);
    CHECK(board.diagRightWin() == playerW);
	CHECK(board.evaluate() == playerW);
}