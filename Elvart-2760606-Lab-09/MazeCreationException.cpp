/**
*	@file:MazeCreationException.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:11/11/15
*	@brief:Renames the std::runtime_error to MazeCreationException in the constructor
*/

#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char* message)
	: std::runtime_error(message)
{
}
