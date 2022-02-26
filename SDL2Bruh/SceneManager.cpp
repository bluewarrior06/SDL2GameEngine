#include "SceneManager.h"

#include <filesystem>

SceneManager::ObjectGroup::ObjectGroup()
{
	this->object_group = new std::vector<ObjectComponent::ObjectComponent*>();
}

SceneManager::ObjectGroup::~ObjectGroup()
{
	this->object_group->clear();
	delete this->object_group;
}

//manipulating the object group list
void SceneManager::ObjectGroup::AddObject(ObjectComponent::ObjectComponent* o)
{
	this->object_group->push_back(o);
}
void SceneManager::ObjectGroup::RemoveObject(std::string name)
{
	for (int i = 0; i < this->object_group->size(); i++)
	{
		if (this->object_group->at(i) != nullptr)
		{
			if (this->object_group->at(i)->name == name)
			{
				this->object_group->erase(this->object_group->begin() + i);
			}
		}
	}
}