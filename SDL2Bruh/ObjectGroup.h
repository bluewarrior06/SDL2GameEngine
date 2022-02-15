#pragma once

#include <string>
#include <vector>

//just got an error on headers including eachother, oh boy I feel like these header inclusions are only gonna get worse and messier
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
};

