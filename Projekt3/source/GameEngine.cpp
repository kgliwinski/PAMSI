#include "../include/GameEngine.hh"


bool GameEngine::init()
{
	board.clearBoard();
	return 1;
}

void GameEngine::printBoard() { board.printBoard(); }

bool GameEngine::mainLoop()
{
	sf::RenderWindow Window = sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (Window.isOpen())
	{
		sf::Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Window.close();
		}

		Window.clear();
		Window.draw(shape);
		Window.display();
	}
	return 1;
}