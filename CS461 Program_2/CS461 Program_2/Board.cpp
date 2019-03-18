// David Tran 
// CS461 
// Program 2
// Connect Four (Monte Carlo Tree Search)

#include "Board.h"

Board::Board() {
	vector<string> zeroth = { "_","_","_","_","_","_","_" }; // top
	layout[0] = zeroth;

	vector<string> oneth = { "_","_","_","_","_","_","_" };
	layout[1] = oneth;

	vector<string> twoth = { "_","_","_","_","_","_","_" };
	layout[2] = twoth;

	vector<string> threeth = { "_","_","_","_","_","_","_" };
	layout[3] = threeth;

	vector<string> fourth = { "_","_","_","_","_","_","_" };
	layout[4] = fourth;

	vector<string> fifth = { "_","_","_","_","_","_","_" }; // bottom
	layout[5] = fifth;
}

int Board::addPiece(string color, int dropCol) {
	int rowR = 0;
	for (int row = 5; row >= 0; row--) {
		if (layout[row][dropCol] == "_") {
			layout[row][dropCol] = color;
			lastAddRow = row;
			lastAddCol = dropCol;
			rowR = row;
			break;
		}
	}
	return rowR;
}

bool Board::fullCol(int colmn) {
	for (int rowNum = 5; rowNum >= 0; rowNum--) {
		if (layout[rowNum][colmn] == "_")
			return false;
	}
	return true;
}

void Board::printLastPos() {
	cout << "Last Row: " << lastAddRow << " Last Col: " << lastAddCol << endl;
}

void Board::printBoard() {
	cout << "Col #" << "   0 1 2 3 4 5 6\n";
	for (int row = 0; row <= 5; row++) {
		cout << "Row #" << row << ": ";
		for (int col = 0; col <= 6; col++) {
			cout << layout[row][col] << " ";
		}
		cout << endl;
	}
}

bool Board::fullBoard() {
	for (int rowNum = 5; rowNum >= 0; rowNum--) {
		for (int colNum = 0; colNum <= 6; colNum++) {
			if (layout[rowNum][colNum] == "_")
				return false;
		}
	}
	return true;
}

bool Board::win(string player) {
	int cnt4 = 0;
	// 4 in a row case
	for (int colCnt = 0; colCnt < 7; colCnt++) {
		if (cnt4 == 4)
			return true;
		else {
			if (layout[lastAddRow][colCnt] == player)
				cnt4++;
			else
				cnt4 = 0;
		}
	}
	cnt4 = 0;
	// 4 in a col case
	for (int rowCnt = 5; rowCnt >= 0; rowCnt--) {
		if (cnt4 == 4)
			return true;
		else {
			if (layout[rowCnt][lastAddCol] == player)
				cnt4++;
			else
				cnt4 = 0;
		}
	}
	cnt4 = 0;
	// 4 in a diagonal case
	vector<string> diagX; // empty diag to iterate through (left to right, going up)
	int lowestRow = lastAddRow;
	int lowestCol = lastAddCol;
	while (lowestRow != 5 && lowestCol != 0) {
		lowestRow += 1;
		lowestCol -= 1;
	}
	diagX.push_back(layout[lowestRow][lowestCol]);
	while (lowestRow != 0 && lowestCol != 6) {
		lowestRow -= 1;
		lowestCol += 1;
		diagX.push_back(layout[lowestRow][lowestCol]);
	}
	for (int itemsDiagX = 0; itemsDiagX < diagX.size(); itemsDiagX++) {
		if (cnt4 == 4)
			return true;
		else {
			if (diagX[itemsDiagX] == player)
				cnt4++;
			else
				cnt4 = 0;
		}
	}
	cnt4 = 0;
	vector<string> diagNegX; // empty diag to iterate through (left to right, going down)
	while (lowestRow != 0 && lowestCol != 0) {
		lowestRow -= 1;
		lowestCol -= 1;
	}
	diagNegX.push_back(layout[lowestRow][lowestCol]);
	while (lowestRow != 5 && lowestCol != 6) {
		lowestRow += 1;
		lowestCol += 1;
	}
	for (int itemsNegDiagX = 0; itemsNegDiagX < diagNegX.size(); itemsNegDiagX++) {
		if (cnt4 == 4)
			return true;
		else {
			if (diagNegX[itemsNegDiagX] == player)
				cnt4++;
			else
				cnt4 = 0;
		}
	}
	return false;
}

bool Board::win(string player, int row, int col) {
	int cnt4 = 0;
	// 4 in a row case
	for (int colCnt = 0; colCnt < 7; colCnt++) {
		if (cnt4 == 4)
			return true;
		else {
			if (layout[row][colCnt] == player)
				cnt4++;
			else
				cnt4 = 0;
		}
	}
	cnt4 = 0;
	// 4 in a col case
	for (int rowCnt = 5; rowCnt >= 0; rowCnt--) {
		if (cnt4 == 4)
			return true;
		else {
			if (layout[rowCnt][col] == player)
				cnt4++;
			else
				cnt4 = 0;
		}
	}
	cnt4 = 0;
	// 4 in a diagonal case
	vector<string> diagX; // empty diag to iterate through (left to right, going up)
	int lowestRow = row;
	int lowestCol = col;
	while (lowestRow != 5 && lowestCol != 0) {
		lowestRow += 1;
		lowestCol -= 1;
	}
	diagX.push_back(layout[lowestRow][lowestCol]);
	while (lowestRow != 0 && lowestCol != 6) {
		lowestRow -= 1;
		lowestCol += 1;
		diagX.push_back(layout[lowestRow][lowestCol]);
	}
	for (int itemsDiagX = 0; itemsDiagX < diagX.size(); itemsDiagX++) {
		if (cnt4 == 4)
			return true;
		else {
			if (diagX[itemsDiagX] == player)
				cnt4++;
			else
				cnt4 = 0;
		}
	}
	cnt4 = 0;
	vector<string> diagNegX; // empty diag to iterate through (left to right, going down)
	while (lowestRow != 0 && lowestCol != 0) {
		lowestRow -= 1;
		lowestCol -= 1;
	}
	diagNegX.push_back(layout[lowestRow][lowestCol]);
	while (lowestRow != 5 && lowestCol != 6) {
		lowestRow += 1;
		lowestCol += 1;
	}
	for (int itemsNegDiagX = 0; itemsNegDiagX < diagNegX.size(); itemsNegDiagX++) {
		if (cnt4 == 4)
			return true;
		else {
			if (diagNegX[itemsNegDiagX] == player)
				cnt4++;
			else
				cnt4 = 0;
		}
	}
	return false;
}