
#include <fstream>
#include <sstream>
#include "myscene.h"
#include <iostream>
using namespace std;

MyScene::MyScene() : Scene()
{
	physicsWorld = new b2World(b2Vec2(0, 20.0f));
	physicsWorld->SetAllowSleeping(false);
	collisionHandler = new CollisionHandler(&physicsEntities);
	physicsWorld->SetContactListener(collisionHandler);

	t.start(); //Timer
	plane = new MyPlane();
	bullet = new MyBullet();
	asteroid = new Asteroid();
	hudobject = new MyHud;
	coin = new MyCoin();
	fuel = new Fuel();
	warningSprite = new MySprite();
	fuelbar = new MySprite();
	background = new MyBackground();
	startFlying = false;
	startFlyingcount = 0;
	
	warningSprite->addSprite("assets/images/warning.tga");
	fuelbar->addSprite("assets/images/fuelbar.tga");

	plane->createPhysics(physicsWorld, Vector2(32, 16));
	asteroid->createPhysics(physicsWorld, Vector2(64, 64));
	coin->createPhysics(physicsWorld, Vector2(32, 32));
	fuel->createPhysics(physicsWorld, Vector2(32, 32));

	physicsEntities.push_back(plane);
	physicsEntities.push_back(asteroid);
	physicsEntities.push_back(coin);
	physicsEntities.push_back(fuel);
	//Define Positions
	warningSprite->position = Point2(SWIDTH / 2 + 1000, SHEIGHT / 2 + 1000);
	fuelbar->position = Point2(0, 30);
	fuelbar->scale.x = 80;
	warningSprite->sprite()->color = RED;
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
	this->addChild(bullet);

	asteroid->physicsBody->SetGravityScale(0);
	coin->physicsBody->SetGravityScale(0);
	fuel->physicsBody->SetGravityScale(0);

	asteroid->physicsBody->SetLinearVelocity(b2Vec2(-10, 1));
	asteroid->physicsBody->SetAngularVelocity(2);

	coin->physicsBody->SetLinearVelocity(b2Vec2(-3, 0));
	fuel->physicsBody->SetLinearVelocity(b2Vec2(-2, 0));

}

MyScene::~MyScene()
{
	delete collisionHandler;
	physicsWorld->SetContactListener(NULL);

	
	this->removeChild(asteroid);
	this->removeChild(fuelbar);
	this->removeChild(hudobject);
	this->removeChild(bullet);
	this->removeChild(coin);
	this->removeChild(background);
	this->removeChild(plane);
	this->removeChild(warningSprite);

	delete hudobject;
	delete asteroid;
	delete plane;
	delete bullet;
	delete fuelbar;
	delete coin;
	delete background;
	delete warningSprite;
	delete physicsWorld;
}

void MyScene::update(float deltaTime)
{
	physicsWorld->Step(deltaTime, 8, 5);
	startFlyingcount += deltaTime;
	warningSprite->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	if (input()->getMouse(0))
	{
		plane->physicsBody->SetTransform(b2Vec2(input()->getMouseX() * 0.02f, input()->getMouseY() * 0.02f), plane->physicsBody->GetAngle());
		plane->physicsBody->SetAngularVelocity(0);
		plane->physicsBody->SetLinearVelocity(b2Vec2(0, 0));
	}

	if (coin->position.x < 0) {
		Point2 currentPosition = coin->position;
		currentPosition.x = 1600 * 0.02f;
		coin->physicsBody->SetTransform(b2Vec2(currentPosition.x, currentPosition.y), coin->rotation);
	}
	if (asteroid->position.x < 0) {
		Point2 currentPosition = asteroid->position;
	}

	if (fuelbar->scale.x < 0) {
		startFlying = false;
	}
	if (startFlying) {
		fuelbar->scale.x -= 5 * deltaTime;
	}
	if (!startFlying) {
		fuelbar->scale.x -= 1 * deltaTime;
		plane->physicsBody->SetGravityScale(0);
		plane->physicsBody->SetTransform(plane->physicsBody->GetPosition(), 0);
		if (startFlyingcount > 3) {
			startFlying = true;
			plane->physicsBody->SetGravityScale(3);
		}
	}

	if (input()->getKeyUp(GLFW_KEY_ESCAPE)) {
		this->stop();
	}

	if (input()->getKeyDown(GLFW_KEY_SPACE)) {
		plane->physicsBody->SetGravityScale(-3);
	}

	if (input()->getKeyUp(GLFW_KEY_SPACE)) {
		plane->physicsBody->SetGravityScale(3);
		plane->physicsBody->SetTransform(plane->physicsBody->GetPosition(), plane->physicsBody->GetAngle() + 1.5f * deltaTime);
	}
	if (input()->getKey(GLFW_KEY_SPACE)) {
		plane->physicsBody->SetTransform(plane->physicsBody->GetPosition(), plane->physicsBody->GetAngle() - 1.5f * deltaTime);
	}
	else
	{
		plane->physicsBody->SetTransform(plane->physicsBody->GetPosition(), plane->physicsBody->GetAngle() + 1.5f * deltaTime);
	}
	if (plane->physicsBody->GetAngle() > 45.0f * DEG_TO_RAD) {
		plane->physicsBody->SetTransform(plane->physicsBody->GetPosition(), 45.0f * DEG_TO_RAD);
	}
	if (plane->physicsBody->GetAngle() < -45.0f * DEG_TO_RAD) {
		plane->physicsBody->SetTransform(plane->physicsBody->GetPosition(), -45.0f * DEG_TO_RAD);

	}
	if (plane->position.y > SHEIGHT / 2 - 400 && plane->position.y < SHEIGHT / 2 + 400) {
		warningSprite->position = Point2(SWIDTH / 2 + 1000, SHEIGHT / 2 + 1000);
	}
	if (t.seconds() > 0.0333f) {
		RGBAColor color = warningSprite->sprite()->color;
		warningSprite->sprite()->color = Color::rotate(color, 0.5f);
		t.start();

	}

	checkEntitiesToDestroy();

}

void MyScene::checkEntitiesToDestroy() {
	std::vector<MyJeffreyEntity*>::iterator it = physicsEntities.begin();
	while (it != physicsEntities.end()) {
		if ((*it)->destroyMe) {
			this->removeChild((*it));
			delete (*it);
			it = physicsEntities.erase(it);
		}
		else {
			it++;
		}
	}
}