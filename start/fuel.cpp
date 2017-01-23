/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "fuel.h"

Fuel::Fuel() : Entity()
{
	this->addSprite("assets/images/fuel.tga");
	this->position = Point2(SWIDTH + 80, rand() % 700);
	this->scale.x = 0.25f;
	this->scale.y = 0.25f;
}

Fuel::~Fuel()
{

}

void Fuel::update(float deltaTime)
{
	this->position.x -= 400.0f * deltaTime;
	if (this->position.x <= -4075)
	{
		this->position = Point2(SWIDTH + 80, rand() % 700);
	}
	// ###############################################################
	// Rotate
	// ###############################################################

}
