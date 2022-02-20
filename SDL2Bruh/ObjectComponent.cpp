#include "ObjectComponent.h"
//clear all components in the object
ObjectComponent::Component::Component() { this->component_name = "EmptyComponent"; }
void ObjectComponent::Component::Update(double d) { std::cout << "bruh\n"; }


//add component to vector
void ObjectComponent::Component::AddComponent(Component* component)
{
	this->component_list.push_back(component);
}
//delete component depending on name
void ObjectComponent::Component::RemoveComponent(std::string name)
{
	int i = 0;
	for (Component* c : this->component_list)
	{
		if (c != nullptr)
		{
			if (c->component_name == name)
			{
				delete c;
				this->component_list.erase(this->component_list.begin() + i);
			}
		}
		i++;
	}
}
//return object component
ObjectComponent::Component* ObjectComponent::Component::GetComponent(std::string component_name)
{
	for (Component* c : this->component_list)
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
void ObjectComponent::Object::UpdateComponents(double delta_time)
{
	for (Component* o : this->components)
	{
		if (o != nullptr)
		{
			o->Update(delta_time);
		}
	}
}
//Draw all components
void ObjectComponent::Object::DrawComponents(double delta_time)
{
	for (Component* o : this->components)
	{
		if (o != nullptr)
		{
			o->Draw(delta_time);
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
	c->component_list = o->components;
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



//world object class
