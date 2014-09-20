#pragma once

#include <iostream>
#include <string>

//============================================================

class Board
{

//============================================================

	public:
		Board();
	
		char getValue(int x, int y);
		void move(char token);
		void printBoard();
		void resetBoard();
		void setUpBoard();

		int getMaxMoves();
		void setMaxMoves(int moves);
		int getXMax();
		void setXMax(int yMax);
		int getYMax();
		void setYMax(int yMax);

//============================================================

	private:
		char _board[15][15];
		int _maxMoves;
		int _xMax;
		int _yMax;
		
//============================================================

	protected:

//============================================================

};

//============================================================