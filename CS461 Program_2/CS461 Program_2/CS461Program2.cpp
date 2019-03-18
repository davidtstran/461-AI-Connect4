// David Tran 
// CS461 
// Program 2
// Connect Four (Monte Carlo Tree Search)

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "Board.h"
#include "GameNode.h"
using namespace std;

int AIvAI();
int AIvHuman(); // add later

int main() {
	AIvAI();
	//AIvHuman();
	return 1;
}

int AIvAI() {
	cout << "Connect-4:\n";
	cout << "Positions go from Row 0:5 & Col 0:6\n";
	cout << "Top Left Corner is (Row 0, Col 0)\n";
	cout << "==================================\n";
	Board overall; 
	vector<GameNode> availMoves;
	int gameCnt = 0;
	int maxCol = 0;
	double maxPayoff = 0;
	int redGamesTotal = 50;
	int yellowGamesTotal = 50;
	while (true) {
		//player 1
		for (int c = 0; c <= 6; c++) {
			if (!overall.fullCol(c)) {
				GameNode n(overall, "R", c);
				availMoves.push_back(n);
			}
		}
		while (gameCnt != redGamesTotal) {
			maxPayoff = 0;
			for (int i = 0; i < availMoves.size(); i++) {
				if (availMoves[i].getPayoff() > maxPayoff) {
					maxPayoff = availMoves[i].getPayoff();
				}
			}
			for (int i = 0; i < availMoves.size(); i++) {
				if (availMoves[i].getPayoff() >= maxPayoff) {
					if (gameCnt == redGamesTotal)
						break;
					availMoves[i].simulateGame("R");
					//cout << "Payoff: " << availMoves[i].getPayoff();
					gameCnt++;
				}
			}
		}
		maxPayoff = 0;
		for (int i = 0; i < availMoves.size(); i++) {
			//cout << i << "&" << availMoves[i].getPayoff() << " ";   // prints out the scores for each possible move
			if (availMoves[i].getPayoff() >= maxPayoff)
				maxPayoff = availMoves[i].getPayoff();
		}
		for (int i = 0; i < availMoves.size(); i++) {
			if (availMoves[i].getPayoff() == maxPayoff) {
				maxCol = i;
				cout << "Best Move for R is at Col " << i << endl;
				cout << "R has " << availMoves[i].getWins() << " wins and ";
				cout << availMoves[i].getDraws() << " draws out of " << availMoves[i].getGames() << " games (of the " << gameCnt << " possible games)\n";
				break;
			}
		}
		int row = overall.addPiece("R", maxCol);
		overall.printBoard();
		if (overall.win("R", row, maxCol)) {
			cout << "\nRed has won!!\n";
			break;
		}
		availMoves.clear();
		cout << endl;

		////////////////////////////////////////////

		// player 2
		for (int c = 0; c <= 6; c++) {
			if (!overall.fullCol(c)) {
				GameNode n(overall, "Y", c);
				availMoves.push_back(n);
			}
		}
		gameCnt = 0;
		while (gameCnt != yellowGamesTotal) {
			maxPayoff = 0;
			for (int i = 0; i < availMoves.size(); i++) {
				if (availMoves[i].getPayoff() > maxPayoff) {
					maxPayoff = availMoves[i].getPayoff();
				}
			}
			for (int i = 0; i < availMoves.size(); i++) {
				if (availMoves[i].getPayoff() >= maxPayoff) {
					if (gameCnt == yellowGamesTotal)
						break;
					availMoves[i].simulateGame("Y");
					//cout << "Payoff: " << availMoves[i].getPayoff();
					gameCnt++;
				}
			}
		}
		maxPayoff = 0;
		for (int i = 0; i < availMoves.size(); i++) {
			//cout << i << "&" << availMoves[i].getPayoff() << " ";   // prints out the scores for each possible move
			if (availMoves[i].getPayoff() >= maxPayoff)
				maxPayoff = availMoves[i].getPayoff();
		}
		for (int i = 0; i < availMoves.size(); i++) {
			if (availMoves[i].getPayoff() == maxPayoff) {
				maxCol = i;
				cout << "Best Move for Y is at Col " << i << endl;
				cout << "Y has " << availMoves[i].getWins() << " wins and ";
				cout << availMoves[i].getDraws() << " draws out of " << availMoves[i].getGames() << " games (of the " << gameCnt << " possible games)\n";
				break;
			}
		}
		row = overall.addPiece("Y", maxCol);
		overall.printBoard();
		if (overall.win("Y", row, maxCol)) {
			cout << "\nYellow has won!!\n";
			break;
		}
		if (overall.fullBoard()) {
			cout << "\nGame ends in a draw\n";
			break;
		}
		availMoves.clear();
		cout << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}

int AIvHuman() {
	return 0;
}