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
#include "Board.h"
using namespace std; 

class GameNode {
private:
	double wins = 0;
	double losses = 0;
	double draws = 0;
	double payoff = 0;
	Board defaultB;

public:
	GameNode();
	GameNode(Board b, string play, int cl);
	double getWins();
	double getLosses();
	double getDraws();
	double getGames();
	double getPayoff();
	void printTest();
	void simulateGame(string playr);
};
