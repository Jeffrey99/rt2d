
#include <fstream>
#include <sstream>
#include "menuScene.h"
#include <iostream>
using namespace std;

MyMenuScene::MyMenuScene() : Scene()
{
	t.start(); //Timer
	background = new MySprite();
	background->addSprite("assets/images/menubackground.tga");
	this->addChild(background);
	background->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	background->scale.x = 1.41f;
	background->scale.y = 1.41f;
	//Define Positions

	// create the scene 'tree'
	// add myentity to this Scene as a child.

}

MyMenuScene::~MyMenuScene()
{
	this->removeChild(background);

	delete background;
}

void MyMenuScene::update(float deltaTime)
{

}

