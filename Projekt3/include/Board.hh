#ifndef BOARD_STRUCT_HH
#define BOARD_STRUCT_HH

#include <stdexcept>
#include <string.h>
#include <iostream>

constexpr char player = 'x';
constexpr char opponent = 'o';
constexpr char blank = '_';
constexpr int playerW = 10;
constexpr int opponentW = -10;
constexpr int noWin = 0;

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
	/// \brief Heuristic function, evaluates the boards state
	int evaluate() const;
	/*! \brief Minimax function. Considers all possible ways of game end
	 * \returns the value of the board */
	int minimax() const;
	/// \brief Returns the best possible move for the player
	Move findBestMove() const;
	/// \brief Board setter, for testing
	void setBoard(char *newBoard[], const size_t &newSize);
};

#endif