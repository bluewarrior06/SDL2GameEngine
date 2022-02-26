#pragma once
#include <string>
#include <map>
#include <vector>

#include "ObjectComponent.h"

#include <fstream>

namespace SceneManager
{
	//the current state of the game loading
	enum LoadingStates
	{
		NONE,//useless
		LOADINGMOD,//loading the files and load ROOT scene
		SAVENOTFOUND,//load BASE scene when starting game
		SAVEFOUND,//load .LASTSCENE when starting game
		SAVINGMOD,//game current state 
		FAILED //fail state of the game, create error file.
	};

	enum DetectStates
	{
		HASOPTIONS,
		NOOPTIONS
	};


	//level information that it stored inside a scene
	class SceneMetaData
	{
		//META DATA
		std::string scene_name = "EMPTYSCENE";//name of the scene
		std::string version = 0;//not necessary, just some stats
		bool save = false;//if its supposed to be saved or not
		//META DATA

		//specific meta data
		std::map<std::string, std::string> meta_data;
	};

	class ObjectGroup
	{
		std::vector<ObjectComponent::ObjectComponent*>* object_group;
		ObjectGroup();
		~ObjectGroup();

		void AddObject(ObjectComponent::ObjectComponent*);
		void RemoveObject(std::string name);
	};

	//class that holds scene information and handles scenes / basically the entire game
	class SceneManager
	{
	public:
		std::string current_mod_name;//just the file name of the mod basically

		//scene information
		SceneMetaData* meta_data;
		ObjectGroup* object_main;
		ObjectGroup* object_static;

		/*
		mod files

		file names
		SCENE.META - meta data for a scene
		SCENE.MAIN - main scene information
		.STATIC - static file
		.LASTSCENE - scene information that is saved
		.OPTION - options panel scene, it gets overlayed over everything

		the scene that is always loaded on startup is called "ROOT"
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
		.OPTION

		some files are special, like some level editor files
		.EDITOR - serialized information for level editor
		.ANIMEDITOR - serialized information for animation editor

		scene loading
		load root.

		also some scenes CAN be saved, this isnt making a save though, the save information is the .LASTSCENE file
		what you are just doing is saving the scene state. so like if you made a platformer where you travel between screens and
		wand to save the last scene , you can easily with a setting in META

		filename and scene name are there own independant things.
		filename is simply just the filename and the scene name is just the name of the scene, they don't work in tandem.
		*/

		SceneManager();
		~SceneManager();





		void Update(double delta_time);
		void Draw(double delta_time);
	};


}