/*********************************************************************
** Program name: 	creature.hpp
** Author: 		    Cihan Adrian Towery
** Date: 		    04May17
** Description: 	hpp companion to the  class room
*********************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP
class Room
{
public:
	Room();
	~Room();
	int get_type();
	virtual void set_interact(int s);
	bool get_interact();
	void displayroommessage();

protected:
	Room *west;
	Room *south;
	Room *north;
	Room *east;
	bool interacted;
	int type;


};
#endif