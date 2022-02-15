#pragma once
#include <Box2D.h>

#include "Object.h"

//base object for physics objects
class PhysicsObject : public Object
{
public:
	b2World* world;

	b2BodyDef* body_def;
	b2PolygonShape* body_shape;
	b2Body* body;
	b2Fixture* body_fixture;
	
	PhysicsObject(b2World* world, float32 density, float32 phys_w, float32 phys_h);
	~PhysicsObject();

};

