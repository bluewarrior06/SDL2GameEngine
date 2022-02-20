#pragma once
#include <iostream>
#include <string>
#include <vector>

//think of this like unitys component system, but extremely simple (not simpler, just simple) and no child nodes.
namespace ObjectComponent
{
	//root component for other components
	class Component
	{
	public:
		
		std::string component_name;

		Component();
		~Component() {};
		//main component stuffs
		virtual void Update(double delta_time);
		virtual void Draw(double delta_time) {};

		//way to communicate with other components in main object component list
		std::vector<ObjectComponent::Component*> component_list;//pointer to object components

		void AddComponent(Component* component);
		void RemoveComponent(std::string name);
		Component* GetComponent(std::string name);
	};

	//root object, objects are made of components.
	class Object
	{
	public:
		//object data
		std::string object_name;
		~Object();

		//object
		virtual void Update(double delta_time) {};
		virtual void Draw(double delta_time) {};

		//handing components -it would probably better to a component array class or something
		std::vector<ObjectComponent::Component*> components;
		
		void UpdateComponents(double delta_time);
		void DrawComponents(double delta_time);

		void AddComponent(Component* component);
		void RemoveComponent(std::string name);
		Component* GetComponent(std::string name);
	};
	
	void AddComponent(Object* o, Component* component);
	void RemoveComponent(Object* o, std::string component_name);
	ObjectComponent::Component* GetComponent(Object* o, std::string component_name);

	//function used for quickly creating an object. useful for editor creating objects
	Object* CreateObject();

	//base world object
	class WorldObject : public Object
	{
	};
}