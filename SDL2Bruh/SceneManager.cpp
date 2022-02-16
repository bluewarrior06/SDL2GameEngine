#include "SceneManager.h"

SceneManager::SceneManager()
{
	this->object_group_background = new ObjectGroup();
	this->object_group_main = new ObjectGroup();
	this->object_group_foreground = new ObjectGroup();
	this->object_group_static = new ObjectGroup();

	this->object_group_audio = new ObjectGroup();
	this->object_group_audio_static = new ObjectGroup();
	
}
SceneManager::~SceneManager()
{
	delete this->object_group_background;
	delete this->object_group_main;
	delete this->object_group_foreground;
	delete this->object_group_static;

	delete this->object_group_audio;
	delete this->object_group_audio_static;
}

void SceneManager::Update()
{
	this->object_group_background->Update();
	this->object_group_main->Update();
	this->object_group_foreground->Update();
	this->object_group_static->Update();

	this->object_group_audio->Update();
	this->object_group_static->Update();

}

void SceneManager::Draw()
{
	this->object_group_background->Draw();
	this->object_group_main->Draw();
	this->object_group_foreground->Draw();
	this->object_group_static->Draw();

	this->object_group_audio->Draw();
	this->object_group_static->Draw();
}