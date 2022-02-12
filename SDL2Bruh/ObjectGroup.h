#pragma once

#include <string>
#include <vector>
#include "Object.h"


	

//container for objects
class ObjectGroup
{
public:
	std::vector<Object*> objects;
	void AddObject(Object* object);
	void RemoveObject(Object* object);

	~ObjectGroup();

	void Update();
	void Draw();

	void Clear();


	//havent tested these
	//std::array<Object*, OBJECTSIZE> GetAllObjects();
	std::vector<Object*>* GetObject(std::string name);
	std::vector<Object*>* GetObjectByID(int ID);
	std::vector<Object*>* GetObjectByGroup(std::string group);

};

