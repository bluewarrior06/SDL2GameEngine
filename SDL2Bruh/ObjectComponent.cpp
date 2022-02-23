#include "ObjectComponent.h"
//object constructor
ObjectComponent::Object::Object()
{
	this->component_list = new std::vector<ObjectComponent::Component*>();
}
//object destructor
ObjectComponent::Object::~Object()
{
	//free everything
	this->component_list->clear();
	delete this->component_list;
}



//adds a component too the list
void ObjectComponent::Object::AddComponent(Component* c)
{
	//assign root list to component and add it
	c->root_component_list = this->component_list;
	this->component_list->push_back(c);
}
//removes a component from the list

//logic to game
void ObjectComponent::Object::Update(double delta_time)
{
	for (int i = 0; i < this->component_list->size(); i++)
	{
		this->component_list->at(i)->Update(delta_time);
	}
}
void ObjectComponent::Object::Draw(double delta_time)
{
	for (int i = 0; i < this->component_list->size(); i++)
	{
		this->component_list->at(i)->Update(delta_time);
	}
}

