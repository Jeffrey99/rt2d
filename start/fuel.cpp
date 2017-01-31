/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "fuel.h"

Fuel::Fuel() : MyJeffreyEntity()
{
	this->addSprite("assets/images/fuel.tga");
	this->position = Point2(SWIDTH / 2, rand() % 700);
	this->scale.x = 0.25f;
	this->scale.y = 0.25f;
	this->name = "fuel";
	this->fuelAmmount = 20;
	this->destroyMe = false;
}

Fuel::~Fuel()
{

}

void Fuel::update(float deltaTime)
{
	MyJeffreyEntity::update(deltaTime);
	if (this->position.x < 0) {
		this->physicsBody->SetTransform(b2Vec2(0, this->position.y), this->rotation);
	}

}

int Fuel::pickUp()
{
	//destroyMe = true;
	return fuelAmmount;
}
