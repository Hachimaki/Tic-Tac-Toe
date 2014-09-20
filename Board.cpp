// Board class.  Stores and handles information relating to the board and "pieces."

#include "Board.h"

//============================================================

Board::Board()
{
	// Initial constructor.  Sets up a blank "board"  of max size, even if we aren't going to use all of it.

	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			_board[y][x] = ' ';
		}
	}
}

//============================================================

char Board::getValue(int x, int y)
{
	// Returns the token value or a blank at a specific space.

	return _board[y][x];
}

//============================================================

void Board::move(char token)
{
	// Gets a player's move and puts it on the board.

	int x;
	int y;

	// Get the move coordinates.
	std::cout << "Enter your move's x coordinate: ";
	std::cin >> x;
	while (std::cin.fail())
	{
		std::cout << "Invalid entry." << std::endl << "Enter your move's x coordinate: ";
		std::cin >> x;
	}

	std::cout << "Enter your move's y coordinate: ";
	std::cin >> y;
	while (std::cin.fail())
	{
		std::cout << "Invalid entry." << std::endl << "Enter your move's y coordinate: ";
		std::cin >> y;
	}

	// Check if the space is empty.
	if (_board[y - 1][x - 1] != ' ')
	{
		// If not, someone already placed here.
		std::cout << "You can't move there." << std::endl;
		move(token);
	}

	// Place the token on the board at the desired space.
	_board[y - 1][x - 1] = token;
}

//============================================================

void Board::printBoard()
{
	// Prints the board so the player(s) can see the state of play.
	// Outputs a coordinate grid, dividers between spaces, and the current state of all spaces.

	for (int y = 0; y <= (_yMax * 2) + 1; y++)
	{
		if (y % 2 == 0)
		{
			if (y == 0)
			{
				// Print coordinate labels.
				std::cout << " ";
				for (int x = 0; x < _xMax; x++)
				{
					std::cout << "   " << x + 1;
				}
				std::cout << "   " << std::endl;
			}
			else
			{
				// Print space states, including any tokens.
				std::cout << y / 2;
				for (int x = 0; x < _xMax; x++)
				{
					std::cout << " | " << _board[(y / 2) - 1][x];
				}
				std::cout << " | " << std::endl;
			}
		}
		else
		{
			// Horizontal divider line.  Verticals are indicated by '|'.
			std::cout << "-";
			for (int x = 0; x < _xMax; x++)
			{
				std::cout << "-|--";
			}
			std::cout << "-|" << std::endl;
		}
	}
}

//============================================================

void Board::resetBoard()
{
	// Resets the board for another game.

	char newBoard;

	// Check to see if the players want to play on a different size board.
	std::cout << "Would you like to play on a different size board? (y/n) ";
	std::cin >> newBoard;
	while (std::cin.fail() || (newBoard != 'y' && newBoard != 'Y' && newBoard != 'n' && newBoard != 'N'))
	{
		std::cout << "Invalid entry." << std::endl << "Would you like to play on a different size board? (y/n) ";
		std::cin >> newBoard;
	}

	if (newBoard == 'y' || newBoard == 'Y')
	{
		// If so, completely reset the board.
		setUpBoard();
	}
	else if (newBoard == 'n' || newBoard == 'N')
	{
		// Otherwise, clear the current board using existing dimensions.
		for (int y = 0; y < _yMax; y++)
		{
			for (int x = 0; x < _xMax; x++)
			{
				_board[y][x] = ' ';
			}
		}
	}
	else
	{
	}
}

//============================================================

void Board::setUpBoard()
{
	// Initial setup of the board for gameplay.

	int xMax;
	int yMax;

	// Get the desired dimensions of the board from the player(s).
	// The current minimum is 3, which likely will be unplayable for greater than 3 players due to size.
	// TODO: Calculate and display smallest possible board for 3-4 players.
	std::cout << "Enter the dimensions of the board:" << std::endl;
	std::cout << "Enter the height, between 3 and 15: ";
	std::cin >> yMax;
	while (std::cin.fail() || yMax < 3 || yMax > 15)
	{
		std::cout << "Invalid entry." << std::endl << "Enter the height, between 3 and 15: ";
		std::cin >> yMax;
	}
	setYMax(yMax);

	std::cout << "Enter the width, between 3 and 15: ";
	std::cin >> xMax;
	while (std::cin.fail() || xMax < 3 || xMax > 15)
	{
		std::cout << "Invalid entry." << std::endl << "Enter the width, between 3 and 15: ";
		std::cin >> xMax;
	}
	setXMax(xMax);

	// Clear spaces for play for a board of size inidicated by the players.
	for (int y = 0; y < getYMax(); y++)
	{
		for (int x = 0; x < getXMax(); x++)
		{
			_board[y][x] = ' ';
		}
	}

	// Calculates and stores the maximum number of moves from the total spaces on the board for determining whether or not it is a tied game.
	setMaxMoves(getXMax() * getYMax());
}

//============================================================

// Get and set methods for private variables.

//============================================================

int Board::getMaxMoves()
{
	return _maxMoves;
}

//============================================================

void Board::setMaxMoves(int moves)
{
	_maxMoves = moves;
}

//============================================================

int Board::getXMax()
{
	return _xMax;
}

//============================================================

void Board::setXMax(int xMax)
{
	_xMax = xMax;
}

//============================================================

int Board::getYMax()
{
	return _yMax;
}

//============================================================

void Board::setYMax(int yMax)
{
	_yMax = yMax;
}

//============================================================
