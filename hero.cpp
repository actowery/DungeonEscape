/*********************************************************************
** Program name: 	hero.cpp
** Author: 		    Cihan Adrian Towery
** Date: 		    04May17
** Description: 	class  for Hero creature with special fighting
**					abiities
*********************************************************************/
#include <iostream>
#include "hero.hpp"
//construct
Hero::Hero()
{
	name = "MacGyver ";
	str = 99;
}
//destruct
Hero::~Hero()
{
}
//virtual attack 
int Hero::attack()
{
	int r = rand() % 12 + 1;
	std::cout << "\t->" << name << " attack roll: " << r << "\n";
	return r;
}
//virtual defense
int Hero::defend()
{
	int def;
	int charm = rand() % 2;
	switch (charm)
	{
	case 0:
	{
		std::cout << name << " The silver coin shines and scares the vampyre!!\n"
				<< "from attacking";
		def = 999;
		break;
	}

	case 1:
	{
		def = ((rand() % 10) + 1);
		std::cout << "\t->" << name << " defense roll:" << def << "\n";

		break;

	}
	}


	return def;
}
