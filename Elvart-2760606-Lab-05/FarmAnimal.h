/**     @name:FarmAnimal.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.7.15
*	@brief: A generic representation of an animal that makes a sound m_sound and has name m_name
*/ 

#ifndef FARMANIMAL_H
#define FARMANIMAL_H

#include <string>

class FarmAnimal
{
 public:

	/*
	@pre: none
	@post: a Farm Animal instance will be created and initialized
	@return: none
	*/
	FarmAnimal();
	/*
	@pre: a FarmAnimal instance exists
	@post: none
	@return: the current value of m_name
	*/
	std::string getName() const;
	/*
	@pre: a FarmAnimal exists
	@post: none
	@return: the current value of m_soound
	*/
	std::string getSound() const;
	/*
	@pre: a FarmAnimal exists
	@post: m_name will be changed to the parameter
	@return: none
	*/
	void setName(std::string name);
	/*
	@pre: a FarmAnimal exists
	@post: m_sound will be changed to the parameter
	@return: none
	*/
	void setSound(std::string sound);

 protected:
	std::string m_name;
	std::string m_sound;
	

};


#endif
