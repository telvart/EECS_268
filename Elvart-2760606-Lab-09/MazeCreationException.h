/**
*	@file:MazeCreationException.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:11/11/15
*	@brief:A renaming of std::runtime_error, thrown when an error creating the 2D char array in MazeReader.h occurs
*/

#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H
#include <stdexcept>

class MazeCreationException: public std::runtime_error
{
 public:
          /**
          * @post Creates an exception with the message
          */
          MazeCreationException(const char* message);
};

#endif
