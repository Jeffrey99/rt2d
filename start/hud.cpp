/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "hud.h"

MyHud::MyHud() : Entity()
{
	this->position = Point2(SWIDTH / 2 , 31.5f);
	this->scale.x = SWIDTH;
	this->scale.y = 1.0f;
	this->addSpriteSheet("assets/images/hudbar.tga", 8, 1);
}

MyHud::~MyHud()
{

}

void MyHud::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################

}
