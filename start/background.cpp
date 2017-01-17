
#include "background.h"


MyBackground::MyBackground() : Entity()
{
	this->addSprite("assets/images/background.tga");
	this->position = Point2(1537 , SHEIGHT / 2);
	this->scale.x = 3.0f;
	this->scale.y = 3.0f;
}

MyBackground::~MyBackground()
{

}

void MyBackground::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	this->sprite()->uvoffset.x += 0.1 * deltaTime;
	// ###############################################################

}
