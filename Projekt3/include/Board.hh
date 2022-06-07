#ifndef BOARD_HH
#define BOARD_HH

#include <stdexcept>
#include <string.h>
#include <iostream>
#include "../include/SFML/Config.hpp"

constexpr char player = 'x';
constexpr char opponent = 'o';
constexpr char blank = '_';
constexpr int playerW = 10;
constexpr int opponentW = -10;
constexpr int noWin = 0;
constexpr int bestDefault = -1000;

struct Move
{
	int row, col;
};

class Board
{
	size_t boardSize;
	char **boardArr;
	public:
	Board(size_t _boardSize);
	~Board();
	/// \brief Checks if there are moves remaining on the board
	bool isMovesLeft() const;
	/// \brief Checks a row if there is a win
	int rowWin(const size_t &rowNum) const;
	/// \brief Checks a col if there is a win
	int colWin(const size_t &colNum) const;
	/// \brief Checks a left-right, top-down diagonal if there is a win
	int diagLeftWin() const;
	/// \brief Cheks a right-left, top down diagonal if there is a win
	int diagRightWin() const;
	/// \brief Heuristic function, evaluates the boards state
	int evaluate() const;
	/*! \brief Minimax function. Considers all possible ways of game end
	 * \returns the value of the board */
	int minimax(const unsigned int &depth, bool isMax) const;
	/// \brief Returns the best possible move for the player
	Move findBestMove() const;
	/// \brief Reallocates the memory and changes size of board, clears the board
	void changeBoardSize(const size_t &newSize);
	/// \brief Board setter, for testing
	void setBoard(char *newBoard[], const size_t &newSize);
	/// \brief Print board in the std out
	void printBoard() const;
	/// \brief clears the board of all signs and sets blank in their place
	void clearBoard();
};

#endif