#include "../include/TerminalEngine.hh"

void TerminalEngine::forcePlayerMove()
{
	std::cout << "Insert where do you want to place " << player << " (row, column)";
	Move move;
	std::cin >> move;
	while (!makePlayerMove(move))
	{
		std::cout << "ERROR: cell is already selected, try again" << std::endl;
		std::cin >> move;
	}
	std::cout << player << " placed:" << std::endl;
	board.printBoard();
}

void TerminalEngine::gameLoop()
{
	board.clearBoard();
	std::cout << "The game starts" << std::endl;
	while (1)
	{
		TerminalEngine::forcePlayerMove();
		if (board.evaluate() == playerW)
		{
			std::cout << "Player won!" << std::endl;
			return;
		}
		if (!TerminalEngine::makeAIMove())
		{
			std::cout << "Bot sie wywrocil\n";
			break;
		}
		else
		{
			std::cout << "Computer made the move!" << std::endl;
			board.printBoard();
		}
		if (board.evaluate() == opponentW)
		{
			std::cout << "Opponent won!" << std::endl;
			return;
		}
	}
}

void TerminalEngine::mainLoop()
{
	char newOption = 'm';
	//TerminalEngine::showMenu();
	do
	{
		std::cout << "Insert menu option:" << std::endl;
		std::cin >> newOption;
	} while (processOptions(newOption));
}

void TerminalEngine::showMenu()
{
	std::cout << "Menu for circe-cross:\n";
	std::cout << " s - start the game\n";
	std::cout << " d - change the AI depth\n";
	std::cout << " b - change board size\n";
	std::cout << " m - show menu\n";
	std::cout << " k - exit the game\n";

	std::cout << "Current depth: " << depth << std::endl;
	std::cout << "Current board Size: " << board.getBoardSize() << std::endl;
}

bool TerminalEngine::processOptions(const char &option)
{
	size_t newParam;
	switch (option)
	{
	case 's':
	{
		TerminalEngine::gameLoop();
		TerminalEngine::showMenu();
		break;
	}
	case 'd':
	{
		std::cout << "Insert desired AI depth (u_int)" << std::endl;
		std::cin >> newParam;
		if (depth == newParam)
		{
			std::cout << "Depth already selected, equal to " << depth << std::endl;
		}
		else
		{
			depth = newParam;
			std::cout << "Changed depth to " << depth << std::endl;
		}
		break;
	}
	case 'm':
	{
		TerminalEngine::showMenu();
		break;
	}
	case 'k':
	{
		return 0;
		break;
	}
	case 'b':
	{
		std::cout << "Insert new board size (u_int)" << std::endl;
		std::cin >> newParam;
		if (board.getBoardSize() == newParam)
		{
			std::cout << "Board size already selected, equal to " << newParam << std::endl;
		}
		else
		{
			board.changeBoardSize(newParam);
			std::cout << "Changed board size to " << newParam << std::endl;
		}
		break;
	}
	default:
	{
		std::cout << "Wrong option" << std::endl;
		break;
	}
	}
	return 1;
}