
#include "coin.h"

MyCoin::MyCoin() : Entity()
{
	//this->addSprite("assets/images/coin.tga");
	this->position = Point2(SWIDTH / 2 , rand() % 700);
	this->scale.x = 1.0f;
	this->scale.y = 1.0f;
	this->addSprite("assets/images/coin.tga");
}

MyCoin::~MyCoin()
{

}

void MyCoin::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	this->position.x -= 450.0f * deltaTime;
	if (this->position.x <= -175)
	{
		this->position = Point2(SWIDTH, rand() % 700);
	}

	//std::cout << (rand() % 100) + 100 << std::endl;
	// ###############################################################

}
