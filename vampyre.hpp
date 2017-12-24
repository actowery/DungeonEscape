/*********************************************************************
** Program name: 	vampyre.hpp
** Author: 		    Cihan Adrian Towery
** Date: 		    04May17
** Description: 	hpp companion Medusa creature and its abiities
*********************************************************************/
#ifndef VAMPYRE_HPP
#define VAMPYRE_HPP

#include "creature.hpp"
class Vampyre : public Creature
{
public:
	//construct and destruct
	Vampyre();
	~Vampyre();
	//virtual functions
	int attack();
	int defend();

};
#endif