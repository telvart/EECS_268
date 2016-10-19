/**
*	@file:Position.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:11/11/15
*	@brief:Implementation of Methods declared in Position.h
*/

#include "Position.h"


Position::Position(int row, int col)
{
	m_row=row;
	m_col=col;
}

int Position::getRow() const
{
	return m_row;
}

int Position::getCol() const
{
	return m_col;
}
