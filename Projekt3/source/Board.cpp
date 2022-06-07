#include "../include/Board.hh"

Board::Board(size_t _boardSize) : boardSize(_boardSize)
{
	boardArr = new char *[boardSize];
	for (size_t j = 0; j < boardSize; ++j)
	{
		boardArr[j] = new char[boardSize];
	}
}

Board::~Board()
{
	for (size_t j = 0; j < boardSize; ++j)
	{
		delete[] boardArr[j];
	}
	delete[] boardArr;
}

bool Board::isMovesLeft() const
{
	for (size_t i = 0; i < boardSize; i++)
		for (size_t j = 0; j < boardSize; j++)
			if (boardArr[i][j] == blank)
				return true;
	return false;
}

int Board::rowWin(const size_t &rowNum) const
{
	if (rowNum >= boardSize)
	{
		throw std::out_of_range("Row out of range\n");
	}
	size_t i;
	// check if any elements are not equal
	for (i = 0; i < boardSize - 1; ++i)
	{
		if (boardArr[rowNum][i] != boardArr[rowNum][i + 1])
		{
			return noWin;
		}
	}
	if (boardArr[rowNum][0] == player)
	{
		return playerW;
	}
	else if (boardArr[rowNum][0] == opponent)
	{
		return opponentW;
	}
	return noWin;
}

int Board::colWin(const size_t &colNum) const
{
	if (colNum >= boardSize)
	{
		throw std::out_of_range("Row out of range\n");
	}
	size_t i;
	// check if any elements are not equal
	for (i = 0; i < boardSize - 1; ++i)
	{
		if (boardArr[i][colNum] != boardArr[i + 1][colNum])
		{
			return noWin;
		}
	}
	if (boardArr[0][colNum] == player)
	{
		return playerW;
	}
	else if (boardArr[0][colNum] == opponent)
	{
		return opponentW;
	}
	if (boardArr[0][colNum] == blank)
	{
		return noWin;
	}
	return noWin;
}

int Board::diagLeftWin() const
{
	size_t i;
	// check the left-right, top-down diagonal
	for (i = 0; i < boardSize - 1; ++i)
	{
		if (boardArr[i][i] != boardArr[i + 1][i + 1])
		{
			return noWin;
		}
	}
	if (boardArr[0][0] == player)
	{
		return playerW;
	}
	else if (boardArr[0][0] == opponent)
	{
		return opponentW;
	}
	return noWin;
}

int Board::diagRightWin() const
{
	size_t i;
	// check the right-left, top-down diagonal
	for (i = 0; i < boardSize - 1; ++i)
	{
		if (boardArr[i][boardSize - i - 1] != boardArr[i + 1][boardSize - i - 2])
		{
			return noWin;
		}
	}

	if (boardArr[boardSize - 1][0] == player)
	{
		return playerW;
	}
	else if (boardArr[boardSize - 1][0] == opponent)
	{
		return opponentW;
	}
	return noWin;
}

int Board::evaluate() const
{
	size_t row, col;
	int res;
	// check rows for wins
	for (row = 0; row < boardSize; ++row)
	{
		res = rowWin(row);
		if (res == playerW || res == opponentW)
		{
			return res;
		}
	}
	// check columns for wins
	for (col = 0; col < boardSize; ++col)
	{
		res = colWin(col);
		if (res == playerW || res == opponentW)
		{
			return res;
		}
	}
	// check diagonals for victory
	int leftW = diagLeftWin();
	if (leftW == playerW || leftW == opponentW)
	{
		return leftW;
	}
	int rightW = diagRightWin();
	if (rightW == playerW || rightW == opponentW)
	{
		return rightW;
	}
	return noWin;
}

int Board::minimax(const unsigned int &depth, bool isMax) const
{
	int score = this->evaluate();
	if (score == playerW || score == opponentW)
	{
		return score;
	}
	if (!this->isMovesLeft())
	{
		return 0;
	}
	int best = bestDefault;
	if (isMax)
	{
		for (size_t i = 0; i < boardSize; ++i)
		{
			for (size_t j = 0; j < boardSize; ++j)
			{
				if (boardArr[i][j] == blank)
				{
					boardArr[i][j] = player;
					best = std::min(best, minimax(depth + 1, !isMax));
					boardArr[i][j] = blank;
				}
			}
		}
		return best;
	}
	else
	{
		best = bestDefault * (-1);
		for (size_t i = 0; i < boardSize; ++i)
		{
			for (size_t j = 0; j < boardSize; ++j)
			{
				if (boardArr[i][j] == blank)
				{
					boardArr[i][j] = opponent;
					best = std::min(best, minimax(depth + 1, !isMax));
					boardArr[i][j] = blank;
				}
			}
		}
	}
	return best;
}

int Board::minimax(const unsigned int &depth, int nodeIndex, bool maximizingPlayer, int values[], int alpha, int beta) const
{
	if (depth == 3)
		return values[nodeIndex];

	if (maximizingPlayer)
	{
		int best = MIN;

		// Recur for left and
		// right children
		for (unsigned int i = 0; i < boardSize - 1; i++)
		{

			int val = minimax(depth + 1, nodeIndex * 2 + i, false, values, alpha, beta);
			best = std::max(best, val);
			alpha = std::max(alpha, best);

			// Alpha Beta Pruning
			if (beta <= alpha)
				break;
		}
		return best;
	}
	else
	{
		int best = MAX;

		// Recur for left and
		// right children
		for (unsigned int i = 0; i < boardSize - 1; i++)
		{
			int val = minimax(depth + 1, nodeIndex * 2 + i, true, values, alpha, beta);
			best = std::min(best, val);
			beta = std::min(beta, best);

			// Alpha Beta Pruning
			if (beta <= alpha)
				break;
		}
		return best;
	}
}


Move Board::findBestMove() const
{
	Move mover = { -1, -1 };
	int moveVal;
	int bestVal = bestDefault;
	for (size_t i = 0; i < boardSize; ++i)
	{
		for (size_t j = 0; j < boardSize; ++j)
		{
			if (boardArr[i][j] == blank)
			{
				boardArr[i][j] = player;
				moveVal = minimax(0, false);
				boardArr[i][j] = blank;
				if (moveVal > bestVal)
				{
					mover = Move{ (int)i, (int)j };
				}
			}
		}
	}
	return mover;
}

Move Board::findBestMove(const unsigned int &depth, bool maximizingPlayer, int values[], int alpha, int beta) const
{
	Move mover = { -1, -1 };
	int moveVal;
	int bestVal = bestDefault;
	for (size_t i = 0; i < boardSize; ++i)
	{
		for (size_t j = 0; j < boardSize; ++j)
		{
			if (boardArr[i][j] == blank)
			{
				boardArr[i][j] = player;
				moveVal = minimax(depth, 0, maximizingPlayer, values, alpha, beta);
				boardArr[i][j] = blank;
				if (moveVal > bestVal)
				{
					mover = Move{ (int)i, (int)j };
				}
			}
		}
	}
	return mover;
}

void Board::setBoard(char *newBoard[], const size_t &newSize)
{
	for (size_t i = 0; i < boardSize; ++i)
	{
		memcpy(boardArr[i], newBoard[i], newSize);
	}
}

void Board::changeBoardSize(const size_t &newSize)
{
	for (size_t j = 0; j < boardSize; ++j)
	{
		delete[] boardArr[j];
	}
	delete[] boardArr;
	boardSize = newSize;
	boardArr = new char *[boardSize];
	for (size_t j = 0; j < boardSize; ++j)
	{
		boardArr[j] = new char[boardSize];
	}
	this->clearBoard();
}

size_t Board::getBoardSize() const
{
	return this->boardSize;
}

void Board::printBoard() const
{
	for (size_t i = 0; i < boardSize; ++i)
	{
		for (size_t j = 0; j < boardSize; ++j)
		{
			std::cout << boardArr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Board::clearBoard()
{
	for (size_t i = 0; i < boardSize; ++i)
	{
		for (size_t j = 0; j < boardSize; ++j)
		{
			boardArr[i][j] = blank;
		}
	}
}