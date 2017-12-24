/*********************************************************************
** Program name: 	daughterrooms.cpp
** Author: 		    Cihan Adrian Towery
** Date: 		    04May17
** Description: 	holds all subrooms used in final proj program
*********************************************************************/
#ifndef DAUGHTERROOMS_HPP
#define DAUGHTERROOMS_HPP

#include "room.hpp"
class NW : public Room
{
public:
	//construct and destruct
	NW();
	~NW();
	//virtual functions
	void set_interact(int);


};
class SW : public Room
{
public:
	//construct and destruct
	SW();
	~SW();
	//virtual functions
	void set_interact(int);


};
class NE : public Room
{
public:
	//construct and destruct
	NE();
	~NE();
	//virtual functions
	void set_interact(int);


};
class SE : public Room
{
public:
	//construct and destruct
	SE();
	~SE();
	//virtual functions
	void set_interact(int);


};

class Guard : public Room
{
public:
	//construct and destruct
	Guard();
	~Guard();
	//virtual functions
	void set_interact(int);


};

class Wayout : public Room
{
public:
	//construct and destruct
	Wayout();
	~Wayout();
	//virtual functions
	void set_interact(int);


};
#endif