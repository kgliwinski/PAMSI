#ifndef GAME_ENGINE_HH
#define GAME_ENGINE_HH

#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <iostream>

#include "Engine.hh"

constexpr int screenWidth = 1024;
constexpr int screenHeight = 1024;

class GameEngine : public Engine
{
	private:
	GameEngine() {}
    static sf::RenderWindow Window;
    
    public:
    GameEngine(GameEngine const &) = delete;
	void operator=(GameEngine const &) = delete;

    static bool init();
    static bool updateWindow();
    static bool mainLoop();

    static void printBoard();
};

#endif