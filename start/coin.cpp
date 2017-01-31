
#include "coin.h"

MyCoin::MyCoin() : MyJeffreyEntity()
{
	//this->addSprite("assets/images/coin.tga");
	this->position = Point2(SWIDTH / 2 + 800, rand() % 700);
	this->scale.x = 1.0f;
	this->scale.y = 1.0f;
	this->addSprite("assets/images/coin.tga");
	this->name = "coin";

}

MyCoin::~MyCoin()
{

}

void MyCoin::update(float deltaTime)
{
	MyJeffreyEntity::update(deltaTime);
	// ###############################################################
	// Rotate
	//std::cout << (rand() % 100) + 100 << std::endl;
	// ###############################################################

}
