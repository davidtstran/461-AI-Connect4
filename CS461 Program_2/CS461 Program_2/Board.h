// David Tran 
// CS461 
// Program 2
// Connect Four (Monte Carlo Tree Search)

#pragma once
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>
using namespace std;

class Board {
private:
	map<int, vector<string>> layout; // 6 rows and 7 cols
	int lastAddRow;
	int lastAddCol;

public:
	Board();
	int addPiece(string color, int dropCol);
	bool fullCol(int colmn);
	void printLastPos();
	void printBoard();
	bool fullBoard();
	bool win(string player);
	bool win(string player, int row, int col);
};