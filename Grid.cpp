// ----------------------------------------------------------------------------
//
// Grid class
//    Implementation
//
//    Version: 
// //
// ----------------------------------------------------------------------------
//
// Generating using Edward Aryee Class Generator
// Author: Edward Aryee
// Date: April 30, 2014
// Modified: --
//
// ----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <assert.h>
#include <sstream>
#include "Grid.h"

using namespace std;

//----------------------------------------------------------------------------
//----- Constructors----------------------------------------------------------
//----------------------------------------------------------------------------

Grid::Grid()
{
//Add null constructor
}

Grid::Grid(const unsigned int& rows, const unsigned int& columns)
{
	for(unsigned int i=0; i < rows; i++)
	{
	 grid_.push_back(vector<int>(columns, 1));
	}
}

Grid::Grid(const vector< vector<int> >& inputGrid)
{
	for(unsigned int i = 0; i <= inputGrid.size(); i++)
	{
		for(unsigned int j = 0; j <= inputGrid[i].size(); i++)
		{
		 grid_[i][j] = inputGrid[i][j];
		}
	}
}

//----------------------------------------------------------------------------
//----- Destructor----------------------------------------------------------
//----------------------------------------------------------------------------

Grid::~Grid()
	{

	}

//----------------------------------------------------------------------------
//----- Inspectors----------------------------------------------------------
//----------------------------------------------------------------------------
//Note for vector types, the inspectors will need to be corrected

bool Grid::isLegalMove(const int& startPosRow, const int& startPosColumn, const int& endPosRow, const int& endPosColumn) const
{
	bool isLegal = (//Check that start positions are withing the board
					startPosRow >= 0 && 
					startPosColumn >= 0 &&
					endPosRow < grid_.size() && 
					endPosColumn < grid_[0].size() && 
					//Check that the distance being moved in less than two spaces in any direction
					abs(startPosRow - endPosRow) <= 2 &&
					abs(startPosColumn - endPosColumn) <= 2 &&
					//Check that there is a peg at the start point, and at the middle point, but not at the end point
					grid_[startPosRow][startPosColumn] == 1 &&
					grid_[((startPosRow + endPosRow)/2)][((startPosColumn + endPosColumn)/2)] == 1 &&
					grid_[endPosRow][endPosColumn] == 0);
	return isLegal;
}

vector< vector<int> > Grid::getGrid() const
{
	return grid_;
}

//----------------------------------------------------------------------------
//----- Mutators----------------------------------------------------------
//----------------------------------------------------------------------------
//Note for vector types, the mutators will need to be corrected

void Grid::applyMove(const int& startPosRow, const int& startPosColumn, const int& endPosRow, const int& endPosColumn)
{
	grid_[startPosRow][startPosColumn] = 0;
	grid_[((startPosRow + endPosRow)/2)][((startPosColumn + endPosColumn)/2)] = 0;
	grid_[endPosRow][endPosColumn] = 1;
}

bool Grid::removeFirst(const int& firstPosRow, const int& firstPosColumn)
{
	bool legalFirst = (firstPosRow < grid_.size() && firstPosColumn <grid_[0].size());
		if(legalFirst)
		{
		grid_[firstPosRow][firstPosColumn] = 0;
		}
		else
		{
		cout << "Illegal first move, please enter again: ";
		}
		return legalFirst;
}


//----------------------------------------------------------------------------
//----- Facilitators----------------------------------------------------------
//----------------------------------------------------------------------------

void Grid::output(ostream& out)
{
	string dashString;

	out << endl;
	int count = 0;
	for(unsigned int i = 0; i < grid_.size(); i++)
	{
		if(count == 0){ // for setting up the header numbers and the first line of -----
			out << setw(grid_[i].size()) << ""; // move over 2 blanck spaces CONST
			for(unsigned int j = 0; j < grid_[0].size(); j++) // for outputting the header numbers
			{
			out << setw(grid_[i].size()-1) << j; // output the header numbers
			}
			out << endl; // new line
			out << setw(grid_[i].size()-1) << "" << "+"; // output corner +
			for(unsigned int k = 0; k < grid_[i].size(); k++) // for setting up the header --------
			{
				for(unsigned int l = 0; l < (grid_[i].size()); l++) // creating a sized string of -
				{
					if(k == grid_[i].size()-1)//int k is the last one
					{
					dashString = "--+";
					out << dashString;
					l = (grid_[i].size())+1;
					}
					else
					{
					dashString = "-";
					out << dashString;
					}
				}
			 // output the header --------
			}
			count++; // end header section
			i--; // reset the table's loop to 0 for next portion
			out << endl;
			out << setw(grid_[0].size()-1) << "" << "|";
				for(unsigned int k = 0; k < grid_[0].size(); k++)
				{
				out << setw(grid_[0].size()-1) << "";
				}
				out << setw(grid_[0].size()-1) << "|"	<<  endl;
			}

		else // setting up actual grid
		{ 
			string row;
				switch(i)
				{
				case 0: row = "A";
					break;
				case 1: row = "B";
					break;
				case 2: row = "C";
					break;
				case 3: row = "D";
					break;
				case 4: row = "E";
					break;
				case 5: row = "F";
					break;
				case 6: row = "G";
					break;
				case 7: row = "H";
					break;
				case 8: row = "I";
					break;
				case 9: row = "J";
					break;
				case 10: row = "K";
					break;
				}
		out << setw(grid_[0].size()-1) << row << "|"; // output side numbers and |
		for(unsigned int j = 0; j < grid_[0].size(); j++) // for setting up grid
		{
			if((j+1)%grid_[0].size() == 0)// when a new line is neccessary
			{ 
			out << setw(grid_[0].size()-1) << grid_[i][j] << setw(grid_[0].size()-1) << "|" << endl; 
				out << setw(grid_[0].size()-1) << "" << "|";
				for(unsigned int k = 0; k < grid_[0].size(); k++)
				{
				out << setw(grid_[0].size()-1) << "";
				}
				out << setw(grid_[0].size()-1) << "|"	<<  endl;
			}
			else // output regular array to the grid
			{
			out << setw(grid_[0].size()-1) << grid_[i][j] ;
			}

			}
		}
	}

	if(count == 1) // for setting up the footer -----
	{ 
			out << setw(grid_[0].size()-1) << "" << "+"; // output corner +
			for(unsigned int k = 0; k < grid_[0].size(); k++) // for setting up the header --------
			{
				for(unsigned int l = 0; l < (grid_[0].size()); l++) // creating a sized string of -
				{
					if(k == grid_[0].size()-1)//int k is the last one
					{
					dashString = "---+";
					out << dashString;
					l = (grid_[0].size())+1;
					}
					else 
					{
						
						dashString = "-";
						out << dashString;
					}
				}
			count++; // end header section
			}
	}
}

bool movesLeft(Grid& iGrid)
{
	int numMoves = 0;
	int emptyCount;
	bool movePossibleAtElement1, movePossibleAtElement2, movePossibleAtElement3, movePossibleAtElement4, movePossibleAtElement5, 
		  movePossibleAtElement6, movePossibleAtElement7, movePossibleAtElement8, anyMoves;
	for(unsigned int i = 0; i < iGrid.getGrid().size(); i++)
	{
		for(unsigned int j = 0; j < iGrid.getGrid()[i].size(); j++)
		{//--------------------------------------------------------------
			if(iGrid.getGrid()[i][j] == 0)
			{
			// don't add anything to the number of moves left
			// instead, add to the count of the empty cells
			emptyCount++;
				if(emptyCount >= (((iGrid.getGrid().size())*(iGrid.getGrid()[0].size())))-1) // if the number of empty cells is equal to the size of the grid YOU WIN
				{
					cout << endl << "---------------------------------------------" << endl;
					cout << "Congratulations! You WON!" << endl << endl;
					cout << endl << "---------------------------------------------" << endl;
					return false;
				}
			}
			//--------------------------------------------------------------
			else //(if the element has a one, then check for possible moves
			{
				// May need to check the everthing aroung the element is inbounds
				
				movePossibleAtElement1 = iGrid.isLegalMove(i,j,i+2,j);
				movePossibleAtElement2 = iGrid.isLegalMove(i,j,i-2,j);
				movePossibleAtElement3 = iGrid.isLegalMove(i,j,i,j+2);
				movePossibleAtElement4 = iGrid.isLegalMove(i,j,i,j-2);
				movePossibleAtElement5 = iGrid.isLegalMove(i,j,i+2,j+2);
				movePossibleAtElement6 = iGrid.isLegalMove(i,j,i+2,j-2);
				movePossibleAtElement7 = iGrid.isLegalMove(i,j,i-2,j+2);
				movePossibleAtElement8 = iGrid.isLegalMove(i,j,i-2,j-2);	
		anyMoves = (movePossibleAtElement1 || movePossibleAtElement2 || movePossibleAtElement3 || movePossibleAtElement4 || movePossibleAtElement5
		    || movePossibleAtElement6 || movePossibleAtElement7 || movePossibleAtElement8);
		if(anyMoves){numMoves++;}
			}
			//--------------------------------------------------------------
		}
	}
	if(numMoves <= 0)
	{
		cout << endl << "---------------------------------------------" << endl;
		cout << endl << "You LOST!" << endl;
		cout << endl << "---------------------------------------------" << endl;
		return false;
	}
	else{return true;}
}
//----------------------------------------------------------------------------
//----- Operators----------------------------------------------------------
//----------------------------------------------------------------------------
// fill in everything in quotation marks

ostream& operator<< (ostream& out,Grid& inputGrid)
	{
		inputGrid.output(out) ;
		return out;
	}
