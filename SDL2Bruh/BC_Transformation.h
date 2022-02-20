#pragma once

#include <Box2D.h>
#include "ObjectComponent.h"
class BC_Transformation : public ObjectComponent::Component
{
public:
	b2Vec2 position;

	//moves the position ar
	void Transform(float x, float y);
	void Transform(b2Vec2 dir);
};

