#pragma once
#include <iostream>
#include <string>
#include <vector>

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
		virtual void Update() {};
		virtual void Draw() {};
	};

	//root object for other objects
	class Object
	{
	public:
		//object data
		std::string object_name;
		~Object();

		//object
		virtual void Update() {};
		virtual void Draw() {};

		//handing components
		std::vector<ObjectComponent::Component*> components;
		
		void UpdateComponents();
		void DrawComponents();

		void AddComponent(Component* component);
		void RemoveComponent(std::string name);
		Component* GetComponent(std::string name);
	};
	
	void AddComponent(Object* o, Component* component);
	void RemoveComponent(Object* o, std::string component_name);
	ObjectComponent::Component* GetComponent(Object* o, std::string component_name);

	//function used for quickly creating an object. useful for editor creating objects
	Object* CreateObject();
}