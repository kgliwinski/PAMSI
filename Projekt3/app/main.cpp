#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sys/resource.h>


#ifdef TERMINAL_ENGINE
#include "../include/TerminalEngine.hh"

int main()
{
	
}

#endif

#ifndef TERMINAL_ENGINE
#include "../include/GameEngine.hh"
int main()
{
	GameEngine::init();
	GameEngine::printBoard();
	GameEngine::mainLoop();
	GameEngine::changeBoardSize(4);
	GameEngine::printBoard();
}
#endif