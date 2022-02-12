#pragma once

#include <iostream>

//main object class for other objects to inherit off of
class Object
{
public:
	std::string name = "Object";
	int ID;
	std::string group;
	
	Object();
	~Object();

	virtual void Update();
	virtual void Draw();
};