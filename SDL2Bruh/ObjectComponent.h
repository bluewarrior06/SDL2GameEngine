#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <string>



//think of this like unitys component system, but extremely simple (not simpler, just simple) and no child nodes.
namespace ObjectComponent
{
	//main container class
	
	//dont use as a component, just as a base component to make more base components or components in general
	class Component
	{
	public:
		//component information
		static inline std::string name = "RootComponent";
		std::vector<Component*>* root_component_list;

		//get a component in the list
		//          V return type
		template <class _Component>_Component* GetComponent(std::string name)
		{
			for (int i = 0; i < this->root_component_list->size(); i++)
			{
				if (this->root_component_list->at(i) != nullptr)
				{
					if (this->root_component_list->at(i)->name == name)
					{
						return static_cast<_Component*>(this->root_component_list->at(i));
					}
				}
			}
		}

		void AddComponent(Component* c);
		void RemoveComponent(std::string name);

		//component logic
		void Update(double delta_time) {};
		void Draw(double delta_time) {};
	};

	//test component, not supposed to be used practically
	class DerivedComponent : public Component
	{
	public:
		static inline std::string name = "BruhMoment";
		static inline int b = 69420;
	};

	//main object class

	//inheriting this object is only supposed to be used as a quick way to add components.
	//eg. World Component - object with Transform component already in it, eg2. Entity - Object that holds a bunch of entity components (such as a rigidbody component, collision shape, AI component, etc etc...)
	//FYI ONLY USE COMPONENTS ONCE IN THE LIST, well you can, but it would probably be a bit difficult at getting some other components with the same name.
	class Object
	{
	public:
		std::vector<Component*>* component_list;

		Object();
		~Object();

		void AddComponent(Component* c);
		void RemoveComponent(std::string name);

		void Update(double delta_time);
		void Draw(double delta_time);
	};




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