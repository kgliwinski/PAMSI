#include "../include/Engine.hh"


Board Engine::board = Board(3);

void Engine::changeBoardSize(const size_t &newSize)
{
    board.changeBoardSize(newSize);
}