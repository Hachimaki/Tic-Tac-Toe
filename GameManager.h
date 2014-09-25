#pragma once

#include <ctime>
#include <iostream>
#include <random>
#include <string>

#include "Board.h"
#include "Player.h"

//============================================================

class GameManager
{

//============================================================

	public:
		GameManager();

		void gameOver();
		void initGame();
		bool isGameWon();
		void runGame();
		void setUpPlayers();

		bool getGameWon();
		void setGameWon(bool gameWon);
		int getNumberOfPlayers();
		void setNumberOfPlayers(int players);
		int getTurn();
		void setTurn(int turn);

//============================================================

	private:
		Board _board;
		bool _gameWon;
		int _numberOfPlayers;
		Player _players[4];
		int _turn;

//============================================================

	protected:
};

//============================================================