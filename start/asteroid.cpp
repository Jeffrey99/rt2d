/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "asteroid.h"

Asteroid::Asteroid() : Entity()
{
	this->addSprite("assets/images/asteroid.tga");
	this->position = Point2(SWIDTH+80, SHEIGHT / 2);
	this->scale.x = 1.0f;
	this->scale.y = 1.0f;

	float turnspeed = rand() % 300;	
}

Asteroid::~Asteroid()
{

}

void Asteroid::update(float deltaTime)
{
	this->position.x -= 0.5f;
	if (this->position.x <= -175)
	{
		this->position = Point2(SWIDTH+80, rand() % 700);
		turnspeed = rand() % 200;
	}
	// ###############################################################
	// Rotate
	this->rotation -= turnspeed * DEG_TO_RAD * deltaTime;
	// ###############################################################

}
