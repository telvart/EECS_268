/**     @name:CyberChicken.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.7.15
*	@brief: Implementation of methods declared in CyberChicken.h
*/ 

#include "CyberChicken.h"

CyberChicken::CyberChicken()
{
	m_name="Cyber Chicken";
	m_sound="Resistance is futile";
}


int CyberChicken::getCyberEggs() const
{
	return m_eggs;
}

void CyberChicken::setCyberEggs(int eggs)
{
	m_eggs=eggs;
}
