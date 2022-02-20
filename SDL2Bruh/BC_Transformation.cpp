#include "BC_Transformation.h"

void BC_Transformation::Transform(float x, float y)
{
	this->position.x += x;
	this->position.y += y;
}

void BC_Transformation::Transform(b2Vec2 dir)
{
	this->position += dir;
}