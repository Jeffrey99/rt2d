
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
		std::stringstream ss;
		ss << "OFG KIJK HOEVEEL FUEL IK EERST HEB!!  ";
		ss << fuel;
		std::cout << ss.str() << std::endl;
		ss = std::stringstream();
		this->fuel += ((Fuel*)entity)->pickUp();
		ss << "OFG KIJK HOEVEEL FUEL IK NU DAN WEL NIET HEB!!  ";
		ss << fuel;
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
	std::cout << fuel << std::endl;
	MyJeffreyEntity::update(deltaTime);
	// ###############################################################
	// Rotate
	// ###############################################################

}
void MyPlane::shoot() {

}
