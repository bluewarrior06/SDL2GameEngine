#pragma once

#include "ObjectGroup.h"
class SceneManager
{
public:
	ObjectGroup* object_group_background;
	ObjectGroup* object_group_main;
	ObjectGroup* object_group_foreground;


	SceneManager();
	~SceneManager();
	
};

