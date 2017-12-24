/*********************************************************************
** Program name: 	vampyre.cpp
** Author: 		    Cihan Adrian Towery
** Date: 		    04May17
** Description: 	class  for Vampyre creature with special fighting
**					abiities
*********************************************************************/
#include <iostream>
#include "vampyre.hpp"
//construct
Vampyre::Vampyre()
{
	name = "Vampyre ";
	str = 18;
}
//destruct
Vampyre::~Vampyre()
{
}
//virtual attack 
int Vampyre::attack()
{
	int r = rand() % 12 + 1;
	std::cout << "\t->" << name << " attack roll: " << r << "\n";
	return r;
}
//virtual defense
int Vampyre::defend()
{
	int def;
	int charm = rand() % 2;
	switch (charm)
	{
	case 0:
	{
		std::cout << name << " Charm prepared for next round!\n";
		def = 999;
		break;
	}

	case 1:
	{
		def = ((rand() % 6) + 1);
		std::cout << "\t->" << name << " defense roll:" << def << "\n";

		break;

	}
	}


	return def;
}
