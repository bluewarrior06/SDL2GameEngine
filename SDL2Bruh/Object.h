#pragma once

#include <iostream>



//main object class for other objects to inherit off of
class Object
{
public:

	std::string name;
	int ID;

	virtual void MainUpdate();//main update that isnt supposed to be edited. the main update is only edited by MainObjects (E.g. PhysicsObject or WorldObject)
	virtual void ObjectUpdate();//update that is what the object does.
	virtual void MainDraw();//main draw that isnt supposed to be edited. the main draw is only edited by MainObjects (E.g. PhysicsObject or WorldObject)
	virtual void ObjectDraw();//draw that is what the object does.
};