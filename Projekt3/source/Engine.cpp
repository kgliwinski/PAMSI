#include "../include/Engine.hh"


Board Engine::board = Board(3);
unsigned int Engine::depth = 1;

void Engine::init()
{
	board.clearBoard();
}

void Engine::changeBoardSize(const size_t &newSize) { board.changeBoardSize(newSize); }

size_t Engine::getBoardSize() { return board.getBoardSize(); }

void Engine::setDepth(const unsigned int &newDepth) { depth = newDepth; }

unsigned int Engine::getDepth() { return depth; }

bool Engine::makeAIMove()
{
	Move move = board.findBestMove(depth);
    try
	{
		return board.insertMove(move, opponent);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;

}

bool Engine::makePlayerMove(const Move &move)
{
	try
	{
		return board.insertMove(move, player);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

