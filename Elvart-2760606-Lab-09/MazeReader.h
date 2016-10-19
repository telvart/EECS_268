/**
*	@file:MazeReader.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:11/11/15
*	@brief:Reads in mazes from files and converts them to 2D char arrays
*/

#ifndef MAZEREADER_H
#define MAZEREADER_H
#include "MazeCreationException.h"
#include <string>
#include <fstream>

class MazeReader
{

 public:
	/**
	*	@post A MazeReader is created. A 2D char array is allocated with the maze information.
	*	@throws MazeCreationExecption
	*
	*/
	MazeReader(std::string file) throw (MazeCreationException);

	/**
	*	@post The maze is deallocated.
	*/
	~MazeReader();

	/**
	*	@pre the file was formatted and read in correctly
	*	@return Returns pointer to the maze
	*/
	const char* const* getMaze() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the number of columns listed in the file
	*/
	int getCols() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the number of rows listed in the file
	*/
	int getRows() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the starting column
	*/
	int getStartCol() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the starting row
	*/
	int getStartRow() const;

 protected:
	/**
	*	@pre the file is properly formatted
	*	@post the characters representing the maze are stored
	*/
	void readMaze()	throw (MazeCreationException);	

	int m_startRow;
	int m_startCol;
	int m_rows;
	int m_cols;
	char** m_maze;
	std::ifstream inputfile;
};

#endif
