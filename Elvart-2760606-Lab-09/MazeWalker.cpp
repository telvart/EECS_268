/**
*	@file: MazeWalker.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:11/11/15
*	@brief:Implementation of methods declared in MazeWalker.h
*/

#include "MazeWalker.h"
#include "ArrayHelper.h"


MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice)
	:m_curPos(startRow,startCol), m_startPos(startRow,startCol)
{
	m_curStep=1;
	m_searchType=searchChoice;
	m_maze=mazePtr;
	m_rows=rows;
	m_cols=cols;

	m_visited=new int*[rows];

	for (int i=0; i<rows; i++)
	{
		m_visited[i]=new int[cols];
	}

	for (int i=0; i<rows; i++)
	{
		for (int j=0;j<cols;j++)
		{
			m_visited[i][j]=0;
		}
	}
}

MazeWalker::~MazeWalker()
{
	for (int i=0; i<m_rows; i++)
	{
		delete[] m_visited[i];
	}
	delete[] m_visited;
}

bool MazeWalker::walkMaze()
{
	while (!isGoalReached())
	{
		m_visited[m_curPos.getRow()][m_curPos.getCol()]=m_curStep;
		storeValidMoves();

		if (m_searchType==Search::DFS && !m_moveStack.empty())
		{
			move(m_moveStack.top());
			m_moveStack.pop();
		}
		else if (m_searchType==Search::BFS && !m_moveQueue.empty())
		{
			move(m_moveQueue.front());
			m_moveQueue.pop();
		}
		else if (m_moveStack.empty() || m_moveQueue.empty())
		{
			m_visited[m_curPos.getRow()][m_curPos.getCol()]=m_curStep;
			return false;
		}
		m_curStep++;
	}
	
	m_visited[m_curPos.getRow()][m_curPos.getCol()]=m_curStep;

	return true;
}

const int* const* MazeWalker::getVisited() const
{
	return m_visited;
}

int MazeWalker::getVisitedRows() const
{
	return m_rows;
}

int MazeWalker::getVisitedCols() const
{
	return m_cols;
}


const char* const* MazeWalker::getMaze() const
{
	return m_maze;
}


void MazeWalker::storeValidMoves()
{//up -> right -> down -> left

	int currentrow=m_curPos.getRow();
	int currentcol=m_curPos.getCol();

	if (m_searchType==Search::DFS)
	{	
		if ( currentrow >=1 && (m_maze[currentrow-1][currentcol]=='P' || m_maze[currentrow-1][currentcol]=='E') ) //check up
		{
			if (m_visited[currentrow-1][currentcol]==0)			
			{
				Position temp=Position(currentrow-1,currentcol);
				m_moveStack.push(temp);
			}
		}
		if ( currentcol <=m_cols-1 && (m_maze[currentrow][currentcol+1]=='P' || m_maze[currentrow][currentcol+1]=='E')) //check right
		{
			if (m_visited[currentrow][currentcol+1]==0)
			{
				Position temp=Position(currentrow,currentcol+1);
				m_moveStack.push(temp);
			}
		}
		if ( currentrow <m_rows-1 && (m_maze[currentrow+1][currentcol]=='P' || m_maze[currentrow+1][currentcol]=='E')) //check down
		{
			if (m_visited[currentrow+1][currentcol]==0)
			{
				Position temp=Position(currentrow+1,currentcol);
				m_moveStack.push(temp);
			}
		}
		if ( currentcol >=1 && (m_maze[currentrow][currentcol-1]=='P' || m_maze[currentrow][currentcol-1]=='E')) //check left
		{
			if (m_visited[currentrow][currentcol-1]==0)
			{
				Position temp=Position(currentrow,currentcol-1);
				m_moveStack.push(temp);
			}
		}
	}
	else if (m_searchType==Search::BFS)
	{
		if ( currentrow >=1 && (m_maze[currentrow-1][currentcol]=='P' || m_maze[currentrow-1][currentcol]=='E')) //check up
		{	if(m_visited[currentrow-1][currentcol]==0)
			{
				Position temp=Position(currentrow-1,currentcol);
				m_moveQueue.push(temp);
			}
		}
		if ( currentcol <=m_cols-1 && (m_maze[currentrow][currentcol+1]=='P' || m_maze[currentrow][currentcol+1]=='E')) //check right
		{
			if(m_visited[currentrow][currentcol+1]==0)
			{
				Position temp=Position(currentrow,currentcol+1);
				m_moveQueue.push(temp);
			}
		}
		if ( currentrow <m_rows-1 && (m_maze[currentrow+1][currentcol]=='P' || m_maze[currentrow+1][currentcol]=='E')) //check down
		{
			if(m_visited[currentrow+1][currentcol]==0)
			{
				Position temp=Position(currentrow+1,currentcol);
				m_moveQueue.push(temp);
			}
		}
		if ( currentcol >=1 && (m_maze[currentrow][currentcol-1]=='P' || m_maze[currentrow][currentcol-1]=='E')) //check left
		{
			if(m_visited[currentrow][currentcol-1]==0)
			{
				Position temp=Position(currentrow,currentcol-1);
				m_moveQueue.push(temp);
			}
		}
	}
}

void MazeWalker::move(Position& p)
{
	m_curPos=p;
}
		
bool MazeWalker::isGoalReached() const
{
	return (m_maze[m_curPos.getRow()][m_curPos.getCol()]=='E');
}





