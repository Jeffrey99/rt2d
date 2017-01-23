
#include <fstream>
#include <sstream>
#include "myscene.h"
#include <iostream>
using namespace std;

MyScene::MyScene() : Scene()
{
	t.start(); //Timer
	plane = new MyPlane();
	asteroid = new Asteroid();
	hudobject = new MyHud;
	coin = new MyCoin();
	fuel = new Fuel();
	warningSprite = new MySprite;
	fuelbar = new MySprite;
	background = new MyBackground;
	startFlying = false;
	startFlyingcount = 0;

	warningSprite->addSprite("assets/images/warning.tga");
	fuelbar->addSprite("assets/images/fuelbar.tga");

	//Define Positions
	warningSprite->position = Point2(SWIDTH / 2 + 1000 , SHEIGHT / 2  +1000);
	fuelbar->position = Point2(0 ,30);
	fuelbar->scale.x = 80;
	warningSprite->sprite()->color = RED;

	physicsWorld = new b2World(b2Vec2(0, 20.0f));
	physicsWorld->SetAllowSleeping(false);
	 
	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(background);
	this->addChild(coin);
	this->addChild(plane);
	this->addChild(fuel);
	this->addChild(asteroid);
	this->addChild(warningSprite);
	this->addChild(hudobject);
	this->addChild(fuelbar);
	createCollisions();

}

MyScene::~MyScene()
{
	physicsWorld->DestroyBody(blokje1);
	physicsWorld->DestroyBody(asteroidb2);
	physicsWorld->DestroyBody(coinb2);


	this->removeChild(asteroid);
	this->removeChild(fuelbar);
	this->removeChild(hudobject);
	this->removeChild(coin);
	this->removeChild(background);
	this->removeChild(fuel);
	this->removeChild(plane);
	this->removeChild(warningSprite);

	delete hudobject;
	delete asteroid;
	delete plane;
	delete fuelbar;
	delete coin;
	delete fuel;
	delete background;
	delete warningSprite;
	delete physicsWorld;
}

void MyScene::update(float deltaTime)
{
	physicsWorld->Step(deltaTime, 8, 5);
	plane->position = Point2(blokje1->GetPosition().x, blokje1->GetPosition().y) * 50.0f;
	asteroid->position = Point2(asteroidb2->GetPosition().x, asteroidb2->GetPosition().y) * 50.0f;
	coin->position = Point2(coinb2->GetPosition().x, coinb2->GetPosition().y) * 50.0f;
	fuel->position = Point2(fuelb2->GetPosition().x, fuelb2->GetPosition().y) * 50.0f;
	startFlyingcount += deltaTime;
	warningSprite->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	plane->rotation = blokje1->GetAngle();
	asteroid->rotation = asteroidb2->GetAngle();


	if (fuelbar->scale.x < 0) {
		startFlying = false;
	}
	if (startFlying) {
		fuelbar->scale.x -= 5 * deltaTime;
	}
	if (!startFlying) {
		fuelbar->scale.x -= 1 * deltaTime;
		blokje1->SetGravityScale(0);
		blokje1->SetTransform(blokje1->GetPosition(), 0.0f * DEG_TO_RAD);
		if (startFlyingcount > 3) {
			startFlying = true;
			blokje1->SetGravityScale(3);
		}
	}
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
		warningSprite->sprite()->color = Color::rotate(color, 0.5f);
		t.start();

	}
}
void MyScene::createCollisions()
{
	b2BodyDef bodydef;
	b2BodyDef asteroidBody;
	b2BodyDef coinBody;
	b2BodyDef fuelBody;

	fuelBody.position.Set(fuel->position.x * 0.02f, fuel->position.y * 0.02f);
	fuelBody.type = b2_dynamicBody;
	fuelb2 = physicsWorld->CreateBody(&fuelBody);

	coinBody.position.Set(coin->position.x * 0.02f, coin->position.y * 0.02f);
	coinBody.type = b2_dynamicBody;
	coinb2 = physicsWorld->CreateBody(&coinBody);

	asteroidBody.position.Set(asteroid->position.x * 0.02f, asteroid->position.y * 0.02f);
	asteroidBody.type = b2_dynamicBody;
	asteroidb2 = physicsWorld->CreateBody(&asteroidBody);

	bodydef.position.Set(plane->position.x * 0.02f, plane->position.y * 0.02f);
	bodydef.type = b2_dynamicBody;
	blokje1 = physicsWorld->CreateBody(&bodydef);

	b2PolygonShape shape;
	b2PolygonShape asteroidShape;
	b2PolygonShape coinShape;
	b2PolygonShape fuelShape;


	float colliderWidth = 32 * 0.02f; // pixels naar meters
	float colliderHeight = 16 * 0.02f; // pixels naar meters
	shape.SetAsBox(colliderWidth, colliderHeight);

	float colliderWidth2 = 128 * 0.02f; // pixels naar meters
	float colliderHeight2 = 128 * 0.02f; // pixels naar meters
	asteroidShape.SetAsBox(colliderWidth2, colliderHeight2);

	float colliderWidth3 = 32 * 0.02f; // pixels naar meters
	float colliderHeight3 = 32 * 0.02f; // pixels naar meters
	coinShape.SetAsBox(colliderWidth3, colliderHeight3);

	float colliderWidth4 = 32 * 0.02f; // pixels naar meters
	float colliderHeight4 = 32 * 0.02f; // pixels naar meters
	fuelShape.SetAsBox(colliderWidth4, colliderHeight4);

	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1.0f;
	blokje1->CreateFixture(&fixture);

	b2FixtureDef fixture2;
	fixture2.shape = &shape;
	fixture2.density = 1.0f;
	asteroidb2->CreateFixture(&fixture2);

	b2FixtureDef fixture3;
	fixture3.shape = &shape;
	fixture3.density = 1.0f;
	coinb2->CreateFixture(&fixture3);

	b2FixtureDef fixture4;
	fixture4.shape = &shape;
	fixture4.density = 1.0f;
	fuelb2->CreateFixture(&fixture4);

	//blokje1->SetTransform(blokje1->GetPosition(), 0.0f * DEG_TO_RAD);
	//asteroidb2->SetTransform(asteroidb2->GetPosition(), 0.0f * DEG_TO_RAD);
	//coinb2->SetTransform(coinb2->GetPosition(), 0.0f * DEG_TO_RAD);
	//fuelb2->SetTransform(fuelb2->GetPosition(), 0.0f * DEG_TO_RAD);


	asteroidb2->SetGravityScale(0);
	coinb2->SetGravityScale(0);
	fuelb2->SetGravityScale(0);
	asteroidb2->SetLinearVelocity(b2Vec2(-10, 1));
}
