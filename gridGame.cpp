#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <assert.h>
#include <sstream>
#include <ciso646>
#include "Grid.h"

using namespace std;

int main()
{
	int rows, columns;
	int startPosRow, startPosColumn, endPosRow, endPosColumn;
	string startPos, endPos;

	cout << "Enter you game grid's number of rows: ";
		cin >> rows;
	cout << "Enter you game grid's number of columns: ";
		cin >> columns;
	Grid gameGrid(rows,columns);
	cout << gameGrid;
	
	string startPeg;
	int startPegRow, startPegColumn;
	cout << endl;
	cout << "Which peg would be removed to start? ";
		cin >> startPeg;
	startPegRow = int(startPeg[0]-65);
	startPegColumn = int(startPeg[1]-48);
	bool firstMoveOccured = false;
	firstMoveOccured = gameGrid.removeFirst(startPegRow, startPegColumn);
	while(firstMoveOccured == false)
	{
		if(firstMoveOccured){}
		
		else{
		cin >> startPeg;
		startPegRow = int(startPeg[0]-65);
		startPegColumn = int(startPeg[1]-48);
		firstMoveOccured = gameGrid.removeFirst(startPegRow, startPegColumn);
		}
	}

	gameGrid.output(cout);

	while(movesLeft(gameGrid))
	{
	cout << endl << "Enter your move (ex. A3 A1 or 'n' to quit): ";
			cin >> startPos;
				if(startPos.compare("n") == 0)
				{
					cout << "Ending Game" << endl;
					system("PAUSE");
					return 0;
				}
			cin >> endPos;
			
			/*if(startPos.length() < 2 || endPos.length() < 2)
			{
				cout << "Invalid Input, ending game"
			}*/

		startPosRow = int(startPos[0])-65;
		startPosColumn = int(startPos[1]-48);
		endPosRow = int(endPos[0])-65;
		endPosColumn = int(endPos[1]-48);

	bool legal = gameGrid.isLegalMove(startPosRow, startPosColumn, endPosRow, endPosColumn);

	if(legal)
	{
		gameGrid.applyMove(startPosRow, startPosColumn, endPosRow, endPosColumn);
		cout << endl;
		gameGrid.output(cout);
	}
	else 
	{
		cout << "Not avalid move" << endl;
	}
	}
	system("PAUSE");
	return 0;
}