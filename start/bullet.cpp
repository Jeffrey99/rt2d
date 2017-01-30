/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "bullet.h"

MyBullet::MyBullet() : Entity()
{
	this->addSprite("assets/images/bullet.tga");
	this->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->scale.x = 0.125f;
	this->scale.y = 0.125f;
}

MyBullet::~MyBullet()
{

}

void MyBullet::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################

}
