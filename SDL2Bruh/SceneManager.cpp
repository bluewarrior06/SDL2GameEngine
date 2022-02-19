#include "SceneManager.h"

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
void SceneManager::UpdateObjects()
{
	for (ObjectComponent::Object* o : this->object_main->objects)
	{
		if (o != nullptr)
		{
			o->Update();
		}
	}
}
void SceneManager::DrawObjects()
{
	for (ObjectComponent::Object* o : this->object_main->objects)
	{
		if (o != nullptr)
		{
			o->UpdateComponents();
		}
	}
}
void SceneManager::UpdateObjectComponents()
{
	for (ObjectComponent::Object* o : this->object_main->objects)
	{
		if (o != nullptr)
		{
			o->Draw();
		}
	}
}
void SceneManager::DrawObjectComponents()
{
	for (ObjectComponent::Object* o : this->object_main->objects)
	{
		if (o != nullptr)
		{
			o->DrawComponents();
		}
	}
}
