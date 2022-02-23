#include "SceneManager.h"

#include <filesystem>

ObjectGroup::~ObjectGroup()
{
	//delete all objects in vector
	int i = 0;
	for (ObjectComponent::Object* o : this->objects)
	{
		if (o != nullptr)
		{
			delete o;
		}
		i++;
	}
}
//add object to object group
void ObjectGroup::AddObject(ObjectComponent::Object* o)
{
	this->objects.push_back(o);
}
//remove object from object group
void ObjectGroup::RemoveObject(std::string name)
{
	int i = 0;
	for (ObjectComponent::Object* o : this->objects)
	{
		if (o != nullptr)
		{
			delete o;
			this->objects.erase(this->objects.begin() + i);
		}
		i++;
	}
}
//delete all objects and clear the object group
void ObjectGroup::Clear()
{
	this->objects.clear();
}







SceneManager::SceneManager()
{
	this->object_main = new ObjectGroup();
	this->object_static = new ObjectGroup();
}
SceneManager::~SceneManager()
{
	delete this->object_main;
	delete this->object_static;
}
//updaring and rendering all objects and their components
void SceneManager::Update(double delta_time)
{
	for (ObjectComponent::Object* o : this->object_main->objects)
	{
		if (o != nullptr)
		{
			o->Update(delta_time);
		}
	}
}
void SceneManager::Draw(double delta_time)
{
	for (ObjectComponent::Object* o : this->object_main->objects)
	{
		if (o != nullptr)
		{
			o->Draw(delta_time);
		}
	}
}

