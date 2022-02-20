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

		template<class _Component> _Component* Get();
	};

	//root object, objects are made of components.
	class Object
	{
	public:
		//object data
		std::string object_name;

		//object
		virtual void Update(double delta_time) {};
		virtual void Draw(double delta_time) {};

		//handing components -it would probably better to a component array class or something
		std::vector<ObjectComponent::Component*> components;
		
		void UpdateComponents(double delta_time);
		void DrawComponents(double delta_time);

		void AddComponent(Component* component);
		void RemoveComponent(std::string name);
	};
	
	void AddComponent(Object* o, Component* component);
	void RemoveComponent(Object* o, std::string component_name);

	template<class _ComponentType>
	_ComponentType Component_GetComponent(Component* c);

	template<class _ComponentType>
	_ComponentType Object_GetComponent(Object* o);

	//function used for quickly creating an object. useful for editor creating objects
	Object* CreateObject();

	/*
	OCS - Object/Components
	//Base OCS are OCS that setup basic things like Sprite rendering and stuff, while 
	//Default OCS stem off of base OCS to create OCS such as a Tilemap object
	//Normal OCS are objects that are made for the purpose of just adding more functionality, such as creating a OCS or inventory system

	Base object prefix - BO_
	Default object prefix AO_
	normal object previx _ O_

	Base component prefix - BC_
	Default component prefix AC_
	normal object prefix - C_


	
	*/
}