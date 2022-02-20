#include "BO_WorldObject.h"
#include "BC_Transformation.h"

BO_WorldObject::BO_WorldObject()
{
	this->object_name = "Transformation";
	this->AddComponent(new BC_Transformation());
}


BO_WorldObject::~BO_WorldObject()
{
	this->components.clear();
}