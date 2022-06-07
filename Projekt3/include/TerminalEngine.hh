#ifndef TERMINAL_ENGINE_HH
#define TERMINAL_ENGINE_HH

#include "Engine.hh"

class TerminalEngine : public Engine
{
    private:
	TerminalEngine() {}
    
    public:
    TerminalEngine(TerminalEngine const &) = delete;
	void operator=(TerminalEngine const &) = delete;

    
};

#endif