#pragma once
#include <string>
#include <map>

#include <vector>

#include "ObjectComponent.h"

//level information that it stored inside a scene
class SceneMetaData
{
	//META DATA
	std::string scene_name;
	std::string version;
	//META DATA

	//specific meta data
	std::map<std::string, std::string> meta_data;
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
	SceneMetaData meta_data;
	ObjectGroup* object_main;
	ObjectGroup* object_static;

	/*
	file names
	SCENE.META - meta data for a scene
	SCENE.MAIN - main scene information
	.STATIC - static file 
	*/
	
	SceneManager();
	~SceneManager();

	void UpdateObjects(double delta_time);
	void DrawObjects(double delta_time);
	void UpdateObjectComponents(double delta_time);
	void DrawObjectComponents(double delta_time);
};

