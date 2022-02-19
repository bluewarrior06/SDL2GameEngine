#pragma once
#include <string>
#include <map>

#include <vector>

#include "ObjectComponent.h"

//level information that it stored inside a scene
class SceneMetaData
{

};

class ObjectGroup
{
public:
	std::vector<ObjectComponent::Object*> objects;

	~ObjectGroup();

	void AddObject(ObjectComponent::Object* o);
	void RemoveObject(std::string object_name);
	ObjectComponent::Object* GetObject(std::string object_name);
};


class SceneManager
{
public:
	ObjectGroup* object_main;
	ObjectGroup* object_static;
	
	SceneManager();
	~SceneManager();

	void UpdateObjects();
	void DrawObjects();
	void UpdateObjectComponents();
	void DrawObjectComponents();
};

