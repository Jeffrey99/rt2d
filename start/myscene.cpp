/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include "myscene.h"
#include <iostream>
using namespace std;

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	plane = new MyPlane();
	warningSprite = new MySprite;
	plane->position = Point2(SWIDTH / 2 - 300, SHEIGHT / 2);
	warningSprite->position = Point2(SWIDTH / 2 + 1000 , SHEIGHT / 2  +1000);
	plane->addSprite("assets/images/plane.tga");
	plane->scale.x = 1.0f;
	plane->scale.y = 1.0f;
	warningSprite->addSprite("assets/images/warning.tga");
	physicsWorld = new b2World(b2Vec2(0, 20.0f));
	physicsWorld->SetAllowSleeping(false);
	b2BodyDef bodydef;
	bodydef.position.Set(plane->position.x * 0.02f, plane->position.y * 0.02f);
	bodydef.type = b2_dynamicBody;
	blokje1 = physicsWorld->CreateBody(&bodydef);

	b2PolygonShape shape;

	float colliderWidth = 128 * 0.02f; // pixels naar meters
	float colliderHeight = 64 * 0.02f; // pixels naar meters
	shape.SetAsBox(colliderWidth, colliderHeight);

	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1.0f;
	blokje1->CreateFixture(&fixture);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(plane);
	this->addChild(warningSprite);
}


MyScene::~MyScene()
{
	physicsWorld->DestroyBody(blokje1);
	delete physicsWorld;
	// deconstruct and delete the Tree
	this->removeChild(plane);
	this->removeChild(warningSprite);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete plane;
	delete warningSprite;
}

void MyScene::update(float deltaTime)
{
	warningSprite->position = Point2(SWIDTH / 2, SHEIGHT / 2);

	if (input()->getMouse(0))
	{
		blokje1->SetTransform(b2Vec2(input()->getMouseX() * 0.02f, input()->getMouseY() * 0.02f), blokje1->GetAngle());
		blokje1->SetAngularVelocity(0);
		blokje1->SetLinearVelocity(b2Vec2(0, 0));
	}
	physicsWorld->Step(deltaTime, 8, 5);
	
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp( GLFW_KEY_ESCAPE )) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	plane->position = Point2(blokje1->GetPosition().x, blokje1->GetPosition().y) * 50.0f;
	plane->rotation = blokje1->GetAngle();

	if (input()->getKeyDown(GLFW_KEY_SPACE)) {
		blokje1->SetGravityScale(-1);
	}
	if (input()->getKeyUp(GLFW_KEY_SPACE)) {
		blokje1->SetGravityScale(1);
		blokje1->SetTransform(blokje1->GetPosition(), blokje1->GetAngle() + 1.5f * deltaTime);
	}
	if (input()->getKey(GLFW_KEY_SPACE)) {
		blokje1->SetTransform(blokje1->GetPosition(), blokje1->GetAngle() - 1.5f * deltaTime);
	}
	else
	{
		blokje1->SetTransform(blokje1->GetPosition(), blokje1->GetAngle() + 1.5f * deltaTime);
	}
	if (blokje1->GetAngle() > 45.0f * DEG_TO_RAD) {
		blokje1->SetTransform(blokje1->GetPosition(), 45.0f * DEG_TO_RAD);
	}
	if (blokje1->GetAngle() < -45.0f * DEG_TO_RAD) {
		blokje1->SetTransform(blokje1->GetPosition(), -45.0f * DEG_TO_RAD);

	}
	if (plane->position.y > SHEIGHT / 2 - 400 && plane->position.y < SHEIGHT / 2 + 400) {
		warningSprite->position = Point2(SWIDTH / 2 + 1000, SHEIGHT / 2 + 1000);
	}
}
