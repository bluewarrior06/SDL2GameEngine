#include "ObjectComponent.h"

//object
ObjectComponent::ObjectComponent::ObjectComponent()
{
	switch (this->type)
	{
	OBJECT:
		this->component_list = new std::vector<ObjectComponent*>();
		this->ObjectConstructor();
		break;
	COMPONENT:
		this->ComponentConstructor();
		break;
	}
}
ObjectComponent::ObjectComponent::~ObjectComponent()
{
	switch (this->type)
	{
	OBJECT:
		delete this->component_list;
		this->ObjectDestructor();
	COMPONENT:
		this->ComponentDestructor();
	}
}

//component

//OLD, no point in keeping this, in a matter of fact this just increases compile time, I just like it bc
//I just like to keep deprecated code :)
//adds a component to root list
void OLD_ObjectComponent::Component::AddComponent(Component* c)
{
	this->root_component_list->push_back(c);
}
//removes a component from root list
void OLD_ObjectComponent::Component::RemoveComponent(std::string name)
{
	for (int i = 0; i < this->root_component_list->size(); i++)
	{
		if (this->root_component_list->at(i) != nullptr)
		{
			if (this->root_component_list->at(i)->name == name)
			{
				this->root_component_list->erase(this->root_component_list->begin() + i);
			}
		}
	}
}

//object constructor
OLD_ObjectComponent::Object::Object()
{
	this->component_list = new std::vector<OLD_ObjectComponent::Component*>();
}
//object destructor
OLD_ObjectComponent::Object::~Object()
{
	//free everything
	this->component_list->clear();
	delete this->component_list;
}



//adds a component too the list
void OLD_ObjectComponent::Object::AddComponent(Component* c)
{
	//assign root list to component and add it
	c->root_component_list = this->component_list;
	this->component_list->push_back(c);
}
//removes a component from the list
void OLD_ObjectComponent::Object::RemoveComponent(std::string name)
{

}

//logic to game
void OLD_ObjectComponent::Object::Update(double delta_time)
{
	for (int i = 0; i < this->component_list->size(); i++)
	{
		this->component_list->at(i)->Update(delta_time);
	}
}
void OLD_ObjectComponent::Object::Draw(double delta_time)
{
	for (int i = 0; i < this->component_list->size(); i++)
	{
		this->component_list->at(i)->Update(delta_time);
	}
}
