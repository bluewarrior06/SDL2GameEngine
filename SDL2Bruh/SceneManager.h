#pragma once
#include <string>
#include <map>
#include <vector>

#include "ObjectComponent.h"

#include <fstream>



//level information that it stored inside a scene
class SceneMetaData
{
	//META DATA
	std::string scene_name;//name of the scene
	std::string version;//not necessary, just some stats
	bool save;//if its supposed to be saved or not
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

	void Clear();
};


class SceneManager
{
public:
	std::string current_mod_name;
	SceneMetaData* meta_data;
	ObjectGroup* object_main;
	ObjectGroup* object_static;
	
	/*
	mod files

	file names
	SCENE.META - meta data for a scene
	SCENE.MAIN - main scene information
	.STATIC - static file 
	.LASTSCENE - last scene the game was loaded in

	the scene that is always loaded on runtime is called "ROOT"
	the root is basically your main menu file, the root is the main way you navigate throughout the scene.
	root files are never saved to due to it being a menu scene, but meta information is saved
	
	a basic mod would look something like this
	ROOT.META
	ROOT.MAIN
	BASE.META
	BASE.MAIN
	LEVELTWO.META
	LEVELTWO.MAIN
	LEVELTHREE.META
	LEVELTHREE.MAIN
	LEVELFOUR.META
	LEVELFOUR.MAIN
	LEVELFIVE.META
	LEVELFIVE.MAIN
	END.META
	END.MAIN
	.STATIC
	.LASTSCENE

	some files are special, like some level editor files
	.EDITOR - serialized information for level editor
	.ANIMEDITOR - serialized information for animation editor

	scene loading
	load root.
	
	*/
	
	SceneManager();
	~SceneManager();

	//game loading
	void SetModName(std::string mod_name);
	void LoadMod();//loads up the ROOT scene in the mod
	void SaveMod();//saves the game into the MODS_ file
	void StartGame();//loads BASE scene if no .LASTSCENE exists, else it loads the .LASTSCENE file. then it loads .STATIC
	void LoadScene(std::string scene_name);

	void Edit_CreateMod();
	void Edit_LoadMod();
	void Edit_SaveMod();
	

	
	void UpdateObjects(double delta_time);
	void DrawObjects(double delta_time);
	void UpdateObjectComponents(double delta_time);
	void DrawObjectComponents(double delta_time);
};

