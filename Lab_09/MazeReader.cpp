/**
*	@file:MazeReader.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:11/11/15
*	@brief:Implementation of methods declared in MazeReader.h
*/

#include "MazeReader.h"


MazeReader::MazeReader(std::string file) throw (MazeCreationException)
	:inputfile(file)
{
	readMaze();
}


MazeReader::~MazeReader()
{
	for (int i=0; i<m_rows; i++)
	{
		delete[] m_maze[i];
	}
	delete[] m_maze;
}


const char* const* MazeReader::getMaze() const
{
	return m_maze;
}


int MazeReader::getCols() const
{
	return m_cols;
}

int MazeReader::getRows() const
{
	return m_rows;
}


int MazeReader::getStartCol() const
{
	return m_startCol;
}


int MazeReader::getStartRow() const
{
	return m_startRow;
}


void MazeReader::readMaze() throw (MazeCreationException)
{
	if (inputfile)
	{
		inputfile >> m_rows;
		inputfile >> m_cols;
		inputfile >> m_startRow;
		inputfile >> m_startCol;

		if (m_rows<=0 || m_cols<=0)
		{
			throw MazeCreationException("Invalid dimensions for the maze");
		}
		if (m_startRow>m_rows || m_startCol>m_cols)
		{
			throw MazeCreationException("Starting location is out of bounds");
		}

		m_maze=new char*[m_rows];

		for (int i=0;i<m_rows;i++)
		{
			m_maze[i]=new char[m_cols];
		}

		for (int i=0;i<m_rows;i++)
		{
			for (int j=0;j<m_cols;j++)
			{
				inputfile>>m_maze[i][j];
			}
		}
	}
	else
	{
		throw MazeCreationException("The file does not exist");
	}
}
