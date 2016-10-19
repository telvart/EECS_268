/**
*	@file:Position.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:11/11/15
*	@brief:A class that acts as a container for row/column values in the 2D arrays in MazeReader/MazeWalker
*/

#ifndef POSITION_H
#define POSITION_H

class Position
{
 public:
	/**
	*        @post Position created with row and col values set.
	*/
	Position(int row, int col);


	/**
	*	@return row value
	*/
	int getRow() const;

	/**
	*	@return col value
	*/
	int getCol() const;

 private:
	int m_row;
	int m_col;

};

#endif
