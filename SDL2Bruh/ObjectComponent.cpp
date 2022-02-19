#include "ObjectComponent.h"
//clear all components in the object
ObjectComponent::Component::Component() { this->component_name = "EmptyComponent"; }







ObjectComponent::Object::~Object()
{
	int i = 0;
	for (Component* o : this->components)
	{
		delete o;
		this->components.pop_back();
		i++;
	}
}
//Update all components
void ObjectComponent::Object::UpdateComponents()
{
	for (Component* o : this->components)
	{
		if (o != nullptr)
		{
			o->Update();
		}
	}
}
//Draw all components
void ObjectComponent::Object::DrawComponents()
{
	for (Component* o : this->components)
	{
		if (o != nullptr)
		{
			o->Draw();
		}
	}
}






//add component to component vector
void ObjectComponent::Object::AddComponent(Component* c)
{
	ObjectComponent::AddComponent(this, c);
}
//remove components from vector
void ObjectComponent::Object::RemoveComponent(std::string component_name)
{
	ObjectComponent::RemoveComponent(this, component_name);
}
//get component from object
ObjectComponent::Component* ObjectComponent::Object::GetComponent(std::string component_name)
{
	return ObjectComponent::GetComponent(this, component_name);
}










//add a component too an object
void ObjectComponent::AddComponent(Object* o, Component* c)
{
	o->components.push_back(c);
}
//delete component depending on name
void ObjectComponent::RemoveComponent(Object* o, std::string name)
{
	int i = 0;
	for (Component* c : o->components)
	{
		if (c != nullptr)
		{
			if (c->component_name == name)
			{
				delete c;
				o->components.erase(o->components.begin() + i);
			}
		}
		i++;
	}
}
//return object component
ObjectComponent::Component* ObjectComponent::GetComponent(Object* o, std::string component_name)
{
	for (Component* c : o->components)
	{
		if (c != nullptr)
		{
			if (c->component_name == component_name)
			{
				return c;
			}
		}
	}
	return nullptr;
}
//creates a new object by function
ObjectComponent::Object* ObjectComponent::CreateObject()
{
	return new ObjectComponent::Object();
}