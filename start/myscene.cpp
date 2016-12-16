
#include <fstream>
#include <sstream>
#include "myscene.h"
#include <iostream>
using namespace std;

MyScene::MyScene() : Scene()
{
	t.start(); //Timer
	plane = new MyPlane();
	warningSprite = new MySprite;

	//Define Positions
	warningSprite->position = Point2(SWIDTH / 2 + 1000 , SHEIGHT / 2  +1000);
	warningSprite->sprite()->color = RED;

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

	blokje1->SetTransform(blokje1->GetPosition(), 0.0f * DEG_TO_RAD);
}


MyScene::~MyScene()
{
	physicsWorld->DestroyBody(blokje1);

	this->removeChild(plane);
	this->removeChild(warningSprite);

	delete plane;
	delete warningSprite;
	delete physicsWorld;
}

void MyScene::update(float deltaTime)
{
	physicsWorld->Step(deltaTime, 8, 5);
	warningSprite->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	plane->position = Point2(blokje1->GetPosition().x, blokje1->GetPosition().y) * 50.0f;
	plane->rotation = blokje1->GetAngle();

	if (input()->getMouse(0))
	{
		blokje1->SetTransform(b2Vec2(input()->getMouseX() * 0.02f, input()->getMouseY() * 0.02f), blokje1->GetAngle());
		blokje1->SetAngularVelocity(0);
		blokje1->SetLinearVelocity(b2Vec2(0, 0));
	}
	if (input()->getKeyUp( GLFW_KEY_ESCAPE )) {
		this->stop();
	}

	if (input()->getKeyDown(GLFW_KEY_SPACE)) {
		blokje1->SetGravityScale(-3);
	}
	if (input()->getKeyUp(GLFW_KEY_SPACE)) {
		blokje1->SetGravityScale(3);
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
	if (t.seconds() >  0.0333f) {
		RGBAColor color = warningSprite->sprite()->color;
		warningSprite->sprite()->color = Color::rotate(color, 0.1f);
		t.start();

	}
}
