#ifndef TERMINAL_ENGINE_HH
#define TERMINAL_ENGINE_HH

#include <iostream>
#include "Engine.hh"

class TerminalEngine : public Engine
{
	private:
	TerminalEngine() {}

	public:
	TerminalEngine(TerminalEngine const &) = delete;
	void operator=(TerminalEngine const &) = delete;

	static void forcePlayerMove();
	static void gameLoop();
	static void mainLoop();
	static void showMenu();
	static bool processOptions(const char &option);
};

#endif