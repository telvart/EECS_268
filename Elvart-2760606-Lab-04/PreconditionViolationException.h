/**     @name: PreconditionViolationException.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:9.31.15
*	@brief: Inherits from std::runtime_error, its basically a renaming
*/ 

#include <stdexcept>
#ifndef PRECONDITIONVIOLATIONEXCEPTION_H
#define PRECONDITIONVIOLATIONEXCEPTION_H

class PreconditionViolationException: public std::runtime_error
{
 public:
	/*
	This constructor will take the parameter and pass it to the std::runtime_error
	constructor, its essentially just making a runtime error with the name
	PreconditionViolationException
	*/
	PreconditionViolationException(const char* msg);
};

#endif
