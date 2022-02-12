#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(b2World* world, float32 density, float32 w, float32 h)
{
	this->world = world;
	this->body_def = new b2BodyDef();
	this->body_shape = new b2PolygonShape();
	this->body_shape->SetAsBox(w, h);

	this->body = this->world->CreateBody(this->body_def);
	this->body_fixture = this->body->CreateFixture(this->body_shape, density);
}

PhysicsObject::~PhysicsObject()
{
	this->world->DestroyBody(this->body);
}