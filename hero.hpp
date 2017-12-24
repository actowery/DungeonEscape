/*********************************************************************
** Program name: 	hero.hpp
** Author: 		    Cihan Adrian Towery
** Date: 		    04May17
** Description: 	hpp companion hero creature and its abiities
*********************************************************************/
#ifndef HERO_HPP
#define HERO_HPP

#include "creature.hpp"
class Hero : public Creature
{
public:
	//construct and destruct
	Hero();
	~Hero();
	//virtual functions
	int attack();
	int defend();

};
#endif