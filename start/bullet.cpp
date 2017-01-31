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
	this->bulletHit = false;
	this->name = "bullet";

}

MyBullet::~MyBullet()
{

}
void MyBullet::onCollisionEnter(MyJeffreyEntity * entity)
{
	if (entity->name == "asteroid") {
		int dir = rand() % 2;
		dir = (dir == 0) ? -1 : 1; 

		((Asteroid*)entity)->physicsBody->SetLinearVelocity(b2Vec2(0, 0));
		((Asteroid*)entity)->physicsBody->ApplyForceToCenter(b2Vec2(-90000, dir * 90000), true);
		((Asteroid*)entity)->physicsBody->GetFixtureList()->SetSensor(true);
		bulletHit = true;
	}
}

void MyBullet::onCollisionExit(MyJeffreyEntity * entity)
{

}
void MyBullet::update(float deltaTime)
{
	MyJeffreyEntity::update(deltaTime);
	//std::cout << position.x << std::endl;
	//this->position.x += 800.0f*deltaTime;
	if (this->position.x > 5000) {
		destroyMe = true;
	}

}
