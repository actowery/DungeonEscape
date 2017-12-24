/*********************************************************************
** Program name: 	creature.hpp
** Author: 		    Cihan Adrian Towery
** Date: 		    04May17
** Description: 	hpp companion to the abstract class creature 
*********************************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <string>
class Creature
{
public:
	Creature();
	
	 ~Creature();
	virtual int getrstr(int);
	virtual int attack();
	virtual int defend();
	int getstr();
	void set_name();
	void get_name();
	void refresh();
protected:
	int str;
	int ap;
	int dp;
	std::string name;
	
};
int resolvecombat(Creature *&, Creature *&);
#endif