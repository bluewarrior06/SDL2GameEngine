#pragma once

#include "ObjectGroup.h"
class SceneManager
{
public:
	ObjectGroup* object_group_background;
	ObjectGroup* object_group_main;
	ObjectGroup* object_group_foreground;
	ObjectGroup* object_group_static; //never deletes when changing scene


	SceneManager();
	~SceneManager();

	void Update();
	void Draw();
	
};

