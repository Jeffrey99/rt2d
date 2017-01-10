/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "background.h"

MyBackground::MyBackground() : Entity()
{
	this->addSprite("assets/images/background.tga");
	this->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->scale.x = 1.0f;
	this->scale.y = 1.0f;
}

MyBackground::~MyBackground()
{

}

void MyBackground::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################

}
