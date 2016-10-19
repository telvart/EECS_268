/**     @name: PreconditionViolationException.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:9.31.15
*	@brief:The constructor for the PVE class.
*/ 

#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char* msg)
	: std::runtime_error(msg)
{
}
