// 9/25 - End game is broken somewhat.  As is currently written, on a 3x3 board, ends after 6 moves and threw cat game on an obvious win.  Check both.

/*
 *	Game manager class.  Handles all main game execution.
 */

#include "GameManager.h"

//============================================================

GameManager::GameManager()
{
	// Default constructor
}

//============================================================

void GameManager::initGame()
{
	// Run main game process

	// Starting display to let the player know what they're playing.
	std::cout << "*** Tic-Tac-Toe Challenge ***" << std::endl;
	std::cout << "This is a game for two to four players." << std::endl;

	// Set up the players in the game, numbers and details.
	setUpPlayers();

	// Call the board object to set up the board.
	_board.setUpBoard();

	// Set starting turn.
	std::mt19937 randomGenerator(time(0));
	std::uniform_int_distribution<int> startPlayer(1, getNumberOfPlayers());

	setTurn(startPlayer(randomGenerator));

	// Run the game.
	runGame();
}

//============================================================

void GameManager::gameOver()
{
	// Finalizes the current game and sees if the player(s) wants to try again.

	char newGame = ' ';
	char newPlayers = ' ';

	// Reset starting turn.
	// TODO: start with random turn
	setTurn(0);

	// Ask if the player(s) want(s) to play another game
	std::cout << "Would you like to play again? (y/n) ";
	std::cin >> newGame;
	while (std::cin.fail() || (newGame != 'y' && newGame != 'Y' && newGame != 'n' && newGame != 'N'))
	{
		std::cin.clear();
		std::cout << "Invalid entry." << std::endl << "Would you like to play again? (y/n) ";
		std::cin >> newGame;
	}
	
	if (newGame == 'y' || newGame == 'Y')
	{
		// New game.

		// Ask if it will be the same player(s).
		std::cout << "Will the players remain the same? (y/n) ";
		std::cin >> newPlayers;

		while (std::cin.fail() || (newPlayers != 'y' && newPlayers != 'Y' && newPlayers != 'n' && newPlayers != 'N'))
		{
			std::cin.clear();
			std::cout << "Invalid entry." << std::endl << "Will the players remain the same? (y/n) ";
			std::cin >> newPlayers;
		}

		if (newPlayers == 'y' || newPlayers == 'Y') {
			// Same players, so reset the board and start again.
			_board.resetBoard();
			runGame();
		}
		else if (newPlayers == 'n' || newPlayers == 'N')
		{
			// Different players, so set up new players, reset the board and start again.
			setUpPlayers();
			_board.resetBoard();
			runGame();
		}
		else
		{
		}
	}
	else if (newGame == 'n' || newGame == 'N')
	{
		// No new game, quit.

		std::cout << "Thanks for playing!" << std::endl;
	}
	else
	{
	}
}

//============================================================

bool GameManager::isGameWon()
{
	// Currently doesn't trigger a win until after the next player finishes their turn?	

	// Checks to see if the player whose turn it is has won by testing the grid to find three tokens in a row in any direction.

	// Find first token
	for (int y = 0; y < _board.getYMax(); y++)
	{
		for (int x = 0; x < _board.getXMax(); x++)
		{
			if (_board.getValue(x, y) == _players[(getTurn()) % getNumberOfPlayers()].getToken())
			{
				// Test if there are any of the same tokens immediately adjactent to that token
				// if so, test to see if there is another token in that same direction
					// if so, return _gameWon =  true
					// if not, find next token
				if (_board.getValue(x - 1, y - 1) == _players[getTurn() % getNumberOfPlayers()].getToken())
				{
					if (_board.getValue(x - 2, y - 2) == _players[getTurn() % getNumberOfPlayers()].getToken())
					{
						std::cout << _players[getTurn() % getNumberOfPlayers()].getName() << " wins!" << std::endl;
						setGameWon(true);
					}
					else
					{
						// No third
					}
				}
				else if (_board.getValue(x, y - 1) == _players[getTurn() % getNumberOfPlayers()].getToken())
				{
					if (_board.getValue(x, y - 2) == _players[getTurn() % getNumberOfPlayers()].getToken())
					{
						std::cout << _players[getTurn() % getNumberOfPlayers()].getName() << " wins!" << std::endl;
						setGameWon(true);
					}
					else
					{
						// No third
					}
				}
				else if (_board.getValue(x + 1, y - 1) == _players[getTurn() % getNumberOfPlayers()].getToken())
				{
					if (_board.getValue(x + 2, y - 2) == _players[getTurn() % getNumberOfPlayers()].getToken())
					{
						std::cout << _players[getTurn() % getNumberOfPlayers()].getName() << " wins!" << std::endl;
						setGameWon(true);
					}
					else
					{
						// No third
					}
				}
				else if (_board.getValue(x + 1, y) == _players[getTurn() % getNumberOfPlayers()].getToken())
				{
					if (_board.getValue(x + 2, y) == _players[getTurn() % getNumberOfPlayers()].getToken())
					{
						std::cout << _players[getTurn() % getNumberOfPlayers()].getName() << " wins!" << std::endl;
						setGameWon(true);
					}
					else
					{
						// No third
					}
				}
				else if (_board.getValue(x + 1, y + 1) == _players[getTurn() % getNumberOfPlayers()].getToken())
				{
					if (_board.getValue(x + 2, y + 2) == _players[getTurn() % getNumberOfPlayers()].getToken())
					{
						std::cout << _players[getTurn() % getNumberOfPlayers()].getName() << " wins!" << std::endl;
						setGameWon(true);
					}
					else
					{
						// No third
					}
				}
				else if (_board.getValue(x, y + 1) == _players[getTurn() % getNumberOfPlayers()].getToken())
				{
					if (_board.getValue(x, y + 2) == _players[getTurn() % getNumberOfPlayers()].getToken())
					{
						std::cout << _players[getTurn() % getNumberOfPlayers()].getName() << " wins!" << std::endl;
						setGameWon(true);
					}
					else
					{
						// No third
					}
				}
				else if (_board.getValue(x - 1, y + 1) == _players[getTurn() % getNumberOfPlayers()].getToken())
				{
					if (_board.getValue(x - 2, y + 2) == _players[getTurn() % getNumberOfPlayers()].getToken())
					{
						std::cout << _players[getTurn() % getNumberOfPlayers()].getName() << " wins!" << std::endl;
						setGameWon(true);
					}
					else
					{
						// No third
					}
				}
				else if (_board.getValue(x - 1, y) == _players[getTurn() % getNumberOfPlayers()].getToken())
				{
					if (_board.getValue(x + 2, y) == _players[getTurn() % getNumberOfPlayers()].getToken())
					{
						std::cout << _players[getTurn() % getNumberOfPlayers()].getName() << " wins!" << std::endl;
						setGameWon(true);
					}
					else
					{
						// No third
					}
				}
				else
				{
					// None adjacent, skip
				}
			}
		}
	}

	// If we've gotten to this point without setting gameWon to true, no one's won yet.  Test to see if there are no moves left.
	if (_board.getMaxMoves() - getTurn() == 1)
	{
		// No more valid moves.
		std::cout << "Cat's game!  There are no more valid moves.";
		setGameWon(true);

	}

	return getGameWon();
}

//============================================================

void GameManager::runGame()
{
	// Main game thread.

	// For initial start, set the gameWon variable to false (because the game hasn't been won yet).
	setGameWon(false);

	// Game loop.
	do
	{
		// Show the player whose turn it is.
		std::cout << _players[getTurn() % getNumberOfPlayers()].getName() << "'s turn: " << std::endl;

		// Output board.
		_board.printBoard();

		// Get the player's move.
		_board.move(_players[getTurn() % getNumberOfPlayers()].getToken());

		// Change the turn for the next turn.
		setTurn(getTurn() + 1);

		// Check for win condition
	}
	while (!isGameWon());

	// Game has ended, inquire about playing again.
	gameOver();
}

//============================================================

void GameManager::setUpPlayers()
{
	// Set up the player(s) in the game.

	int players;
	std::string playerName;
	char playerToken;
	Player player;

	// Start by asking how many players will be playing.  Can get up to four.

	// TODO: Need to figure out how small the smallest possible board can be in terms of spaces
	// to determine how small the board is allowed to be for more than two players.
	std::cout << "How many players?  Enter a number between 1 and 4: ";
	std::cin >> players;
	while (std::cin.fail() || players < 1 || players > 4)
	{
		std::cin.clear();
		std::cout << "Invalid entry." << std::endl << "How many players?  Enter a number between 1 and 4: ";
		std::cin >> players;
	}
	setNumberOfPlayers(players);

	for (int i = 0; i < players; i++)
	{
		// Set up the player(s)'(s) name(s) and token(s).
		std::cout << "Player 1: what is your name? ";
		std::cin >> playerName;
		std::cout << "What would you like to be your token? ";
		std::cin >> playerToken;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Invalid entry." << std::endl << "What would you like to be your token? ";
			std::cin >> playerToken;
		}

		_players[i].setName(playerName);
		_players[i].setToken(playerToken);

		// Output the details.
		std::cout << "Player " << i << ", your name is " << _players[i].getName() << " and your token is " << _players[i].getToken() << ".\n" <<  std::endl;
	}
}

//============================================================

// Get and set methods for private variables.

//============================================================


bool GameManager::getGameWon()
{
	return _gameWon;
}

//============================================================

void GameManager::setGameWon(bool gameWon)
{
	_gameWon = gameWon;
}

//============================================================

int GameManager::getNumberOfPlayers()
{
	return _numberOfPlayers;
}

//============================================================

void GameManager::setNumberOfPlayers(int players)
{
	_numberOfPlayers = players;
}

//============================================================

int GameManager::getTurn()
{
	return _turn;
}

//============================================================

void GameManager::setTurn(int turn)
{
	_turn = turn;
}

//============================================================