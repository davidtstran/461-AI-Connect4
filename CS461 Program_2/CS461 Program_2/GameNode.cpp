// David Tran 
// CS461 
// Program 2
// Connect Four (Monte Carlo Tree Search)

#include "GameNode.h"

GameNode::GameNode() {
	Board b;
	defaultB = b;
}

GameNode::GameNode(Board b, string play, int cl) {
	defaultB = b;
	defaultB.addPiece(play, cl);
}

double GameNode::getWins() {
	return wins;
}

double GameNode::getLosses() {
	return losses;
}

double GameNode::getDraws() {
	return draws;
}

double GameNode::getGames() {
	return (wins + losses + draws);
}

double GameNode::getPayoff() {
	if ((wins + losses + draws) == 0) {
		payoff = 0;
		return payoff;
	}
	payoff = (wins + (draws / 2)) / (wins + losses + draws);
	return payoff;
}

void GameNode::printTest() {
	defaultB.printBoard();
}

void GameNode::simulateGame(string playr) {
	string player1, player2;
	player1 = playr;
	if (playr == "R")
		player2 = "Y";
	else if (playr == "Y")
		player2 = "R";
	Board testB = defaultB;
	random_device a;
	int randPos;
	while (true) {
		randPos = a() % 7;
		while (testB.fullCol(randPos))
			randPos = a() % 7;
		testB.addPiece(player2, randPos); // P2 goes first (P1 went by default)
		//testB.printBoard();
		if (testB.win(player2)) {
			losses++;
			break;
		}
		if (testB.fullBoard()){
			draws++;
			break;
		}
		randPos = a() % 7;
		while (testB.fullCol(randPos))
			randPos = a() % 7;
		testB.addPiece(player1, randPos); // P1 (initial player)
		//testB.printBoard();
		if (testB.win(player1)) {
			wins++;
			break;
		}
		if (testB.fullBoard()) {
			draws++;
			break;
		}
	}
}