#include "ObjectGroup.h"

#include <iostream>

#include <array>


ObjectGroup::~ObjectGroup()
{

}

void ObjectGroup::Update()
{
	for (Object* o : this->objects)
	{
		if (o != nullptr)
		{
			o->Update();
		}
	}
}

void ObjectGroup::Draw()
{
	for (Object* o : this->objects)
	{
		if (o != nullptr)
		{
			o->Draw();
		}
	}
}

void ObjectGroup::Clear()
{
	for (Object* o : this->objects)
	{
		delete o;
		this->objects.pop_back();
	}
}
//getting objects
std::vector<Object*>* ObjectGroup::GetObject(std::string name)
{
	std::vector<Object*>* return_objects = new std::vector<Object*>();
	for (Object* o : this->objects)
	{
		if (o != nullptr)
		{
			if (o->name.c_str() == name)
			{
				return_objects->push_back(o);
			}
		}
	}
	return return_objects;
}

std::vector<Object*>* ObjectGroup::GetObjectByID(int ID)
{
	std::vector<Object*>* return_objects = new std::vector<Object*>();
	for (Object* o : this->objects)
	{
		if (o != nullptr)
		{
			if (o->ID == ID)
			{
				return_objects->push_back(o);
			}
		}
	}
	return return_objects;
}

std::vector<Object*>* ObjectGroup::GetObjectByGroup(std::string group)
{
	std::vector<Object*>* return_objects = new std::vector<Object*>();
	for (Object* o : this->objects)
	{
		if (o != nullptr)
		{
			if (o->group == group)
			{
				return_objects->push_back(o);
			}
		}
	}
	return return_objects;
}

void ObjectGroup::AddObject(Object* object)
{
	this->objects.push_back(object);
}

void ObjectGroup::RemoveObject(Object* object)
{

}