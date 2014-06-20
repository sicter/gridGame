// ----------------------------------------------------------------------------
//
// Grid class
//    Header
//
// This program will allow for the Grid class to be implemented in order to play ape
// egboard problem game//
// ----------------------------------------------------------------------------
//
// Generating using Edward Aryee Class Generator
// Author: 
// Date: 
// Modified: 
//
// ----------------------------------------------------------------------------

#ifndef _Grid_
#define _Grid_

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <assert.h>
#include <sstream>

using namespace std;
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

class Grid
{
public:
		// ------------------------------------------------------
		// ----- Constructors -----------------------------------
		// ------------------------------------------------------

			Grid();
			Grid(const unsigned int& length, const unsigned int& width);
			Grid(const vector< vector<int> >& inputGrid);

		// ------------------------------------------------------
		// ----- Destructor -------------------------------------
		// ------------------------------------------------------

			~Grid();

		// ------------------------------------------------------
		// ----- Inspectors -------------------------------------
		// ------------------------------------------------------
//Note for vector types, the inspectors will need to be corrected

		bool isLegalMove(const int& startPosRow, const int& startColumn, const int& endPosRow, const int& endPosColumn) const;
		vector< vector<int> > getGrid() const;

		// ------------------------------------------------------
		// ----- Mutators ---------------------------------------
		// ------------------------------------------------------
//Note for vector types, the mutators will need to be corrected

		void applyMove(const int& startPosRow, const int& startColumn, const int& endPosRow, const int& endPosColumn);
		bool removeFirst(const int& firstPosRow, const int& firstPosColumn);
	

		// ------------------------------------------------------
		// ----- Facilitators -----------------------------------
		// ------------------------------------------------------

		void output(ostream& out);

	// ----------------------------------------------------------
	// ----------------------------------------------------------

private:
	vector< vector<int> > grid_;
};

#endif

	// ------------------------------------------------------
	// ----- SubPrograms -----------------------------------
	// ------------------------------------------------------

	bool movesLeft(Grid& iGrid);

// ------------------------------------------------------
// ----- Operators --------------------------------------
// ------------------------------------------------------

	ostream& operator<< (ostream& out,Grid& inputGrid);