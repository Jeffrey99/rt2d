
#include <fstream>
#include <sstream>
#include "menuScene.h"
#include <iostream>
using namespace std;

MyMenuScene::MyMenuScene() : Scene()
{
	background = new MySprite();
	background->addSprite("assets/images/menubackground.tga");
	this->addChild(background);
	background->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	background->scale.x = 1.41f;
	background->scale.y = 1.41f;
	gameScene = false;
	
	clickToStart = new MySprite();
	clickToStart->addSprite("assets/images/clickToStart.tga");
	this->addChild(clickToStart);
	clickToStart->position = Point2(SWIDTH / 2.0f, SHEIGHT / 2.0f);
	clickToStartAlpha = 255;
	clickToStartTimer = 0.0f;
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
	clickToStartTimer += deltaTime * 3.0f;
	clickToStartAlpha = ((std::sin(clickToStartTimer) + 1.0f) / 2.0f) * 255.0f;
	clickToStart->sprite()->color.a = clickToStartAlpha;
	if (input()->getMouseUp(0)) {
		gameScene = true;
	}
}

