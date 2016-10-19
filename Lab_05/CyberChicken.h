/**     @name:CyberChicken.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.7.15
*	@brief: A specialized chicken with a strong will to dominate humanity
*/ 

#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H
#include "Chicken.h"
class CyberChicken: public Chicken
{
 public:
	/*
	@pre: none
	@post: a CyberChicken will be created, m_name will be CyberChicken and m_sound will be Resistance is futile
	@return: none
	*/
	CyberChicken();
	/*
	@pre: a CyberChicken exists
	@post: none
	@return: the current value of m_eggs
	*/
	int getCyberEggs() const;
	/*
	@pre: a CyberChicken exists
	@post: m_eggs will be changed to the parameter
	@return: none
	*/
	void setCyberEggs(int eggs);
};
#endif
