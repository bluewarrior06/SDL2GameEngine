#include "ObjectGroup.h"

#include <iostream>

#include <array>


ObjectGroup::~ObjectGroup()
{
	this->Clear();
}

void ObjectGroup::Update()
{
	for (Object* o : this->objects)
	{
		if (o != nullptr)
		{
			o->MainUpdate();
		}
	}
}

void ObjectGroup::Draw()
{
	for (Object* o : this->objects)
	{
		if (o != nullptr)
		{
			o->MainDraw();
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

//doesnt work
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

void ObjectGroup::AddObject(Object* object)
{
	this->objects.push_back(object);
}

void ObjectGroup::RemoveObject(Object* object)
{
	int i = 0;
	for (Object* o : this->objects)
	{
		if (o != nullptr)
		{
			if (o == object)
			{
				delete o;
				this->objects.erase(this->objects.begin() + i);
			}
		}
		i++;
	}
}