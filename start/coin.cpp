
#include "coin.h"

MyCoin::MyCoin() : Entity()
{
	//this->addSprite("assets/images/coin.tga");
	this->position = Point2(SWIDTH / 2 , rand() % 700);
	this->scale.x = 1.0f;
	this->scale.y = 1.0f;
	this->addSpriteSheet("assets/images/coin.tga",8,1);
}

MyCoin::~MyCoin()
{

}

void MyCoin::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	this->position.x -= 0.28f;
	if (this->position.x <= -175)
	{
		this->position = Point2(SWIDTH, rand() % 700);
	}

	//std::cout << (rand() % 100) + 100 << std::endl;
	// ###############################################################

}
