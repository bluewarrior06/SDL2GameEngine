#include "SceneManager.h"

SceneManager::SceneManager()
{
	this->object_group_background = new ObjectGroup();
	this->object_group_main = new ObjectGroup();
	this->object_group_foreground = new ObjectGroup();

}
SceneManager::~SceneManager()
{
	delete this->object_group_background;
	delete this->object_group_main;
	delete this->object_group_foreground;

}