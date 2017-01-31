/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "bullet.h"

MyBullet::MyBullet() : MyJeffreyEntity()
{
	this->addSprite("assets/images/bullet.tga");
	this->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->scale.x = 0.125f;
	this->scale.y = 0.125f;
	this->bulletSpeed = 10;
	this->destroyTime = 0;
	this->destroyMe = false;
	this->name = "bullet";

}

MyBullet::~MyBullet()
{

}
void MyBullet::onCollisionEnter(MyJeffreyEntity * entity)
{
	if (entity->name == "asteroid") {
		std::cout << this->name << std::endl;
	}
}

void MyBullet::onCollisionExit(MyJeffreyEntity * entity)
{

}
void MyBullet::update(float deltaTime)
{
	//std::cout << position.x << std::endl;
	this->position.x += 800.0f*deltaTime;
	if (this->position.x > 5000) {
		destroyMe = true;
	}

}
