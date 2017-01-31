
#include "plane.h"

MyPlane::MyPlane() : MyJeffreyEntity()
{
	this->addSprite("assets/images/plane.tga");
	this->position = Point2(SWIDTH / 2 - 500, SHEIGHT / 2);
	this->scale.x = 1.0f;
	this->scale.y = 1.0f;
	this->fuel = 100;
}

MyPlane::~MyPlane()
{

}

void MyPlane::onCollisionEnter(MyJeffreyEntity * entity)
{
	if (entity->name == "fuel") {
		this->fuel += ((Fuel*)entity)->pickUp();		
		std::stringstream ss;
		ss << "Fuel pickup";
		std::cout << ss.str() << std::endl;
	}
	if (entity->name == "coin") {
		std::stringstream ss;
		ss << "Coin pickup";
		std::cout << ss.str() << std::endl;
	}
	if (entity->name == "asteroid") {
		std::stringstream ss;
		ss << "Asteroid";
		std::cout << ss.str() << std::endl;
	}
}

void MyPlane::onCollisionExit(MyJeffreyEntity * entity)
{
	if (entity->name == "fuel") {
		fuel += ((Fuel*)entity)->pickUp();
	}
}

void MyPlane::update(float deltaTime)
{
	this->fuel -= 5.0f * deltaTime;
	MyJeffreyEntity::update(deltaTime);
	//std::cout << fuel << std::endl;
	// ###############################################################
	// Rotate
	// ###############################################################

}
void MyPlane::shoot() {
	fuel -= 5.0f;
}
