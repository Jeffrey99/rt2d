
#include "plane.h"

MyPlane::MyPlane() : Entity()
{
	this->addSprite("assets/images/plane.tga");
	this->position = Point2(SWIDTH / 2 - 500, SHEIGHT / 2);
	this->scale.x = 1.0f;
	this->scale.y = 1.0f;
}

MyPlane::~MyPlane()
{

}

void MyPlane::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################

}
