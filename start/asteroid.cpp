/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "asteroid.h"

Asteroid::Asteroid() : Entity()
{
	this->addSprite("assets/images/asteroid.tga");
	this->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->scale.x = 1.0f;
	this->scale.y = 1.0f;
}

Asteroid::~Asteroid()
{

}

void Asteroid::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	
	// ###############################################################

}
