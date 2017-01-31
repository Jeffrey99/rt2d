/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "asteroid.h"

Asteroid::Asteroid() :MyJeffreyEntity()
{
	this->addSprite("assets/images/asteroid.tga");
	this->position = Point2(SWIDTH / 2 + 800, rand() % 700);
	this->scale.x = 1.0f;
	this->scale.y = 1.0f;
	this->name = "asteroid";

}

Asteroid::~Asteroid()
{

}

void Asteroid::update(float deltaTime)
{
	MyJeffreyEntity::update(deltaTime);
	//std::cout << this->position.x << std::endl;
	// ###############################################################
	// Rotate
	// ###############################################################

}
