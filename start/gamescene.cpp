
#include <fstream>
#include <sstream>
#include "gamescene.h"
#include <iostream>
using namespace std;

MyScene::MyScene() : Scene()
{
	physicsWorld = new b2World(b2Vec2(0, 20.0f));
	physicsWorld->SetAllowSleeping(false);
	collisionHandler = new CollisionHandler(&physicsEntities);
	physicsWorld->SetContactListener(collisionHandler);

	plane = new MyPlane();
	asteroid = new Asteroid();
	hudobject = new MyHud;
	coin = new MyCoin();
	fuel = new Fuel();
	warningSprite = new MySprite();
	fuelbar = new MySprite();
	background = new MyBackground();
	scoreText = new Text();
	startFlying = false;
	startFlyingcount = 0;
	points = 0;
	outscreenTimer = 0;

	warningSprite->addSprite("assets/images/warning.tga");
	warningSprite->sprite()->color = WHITE;
	fuelbar->addSprite("assets/images/fuelbar.tga");

	plane->createPhysics(physicsWorld, Vector2(32, 16));
	asteroid->createPhysics(physicsWorld, Vector2(32, 32));
	coin->createPhysics(physicsWorld, Vector2(32, 32));
	fuel->createPhysics(physicsWorld, Vector2(32, 32));

	physicsEntities.push_back(plane);
	physicsEntities.push_back(asteroid);
	physicsEntities.push_back(coin);
	physicsEntities.push_back(fuel);
	//Define Positions
	warningSprite->position = Point2(SWIDTH / 2 + 1000, SHEIGHT / 2 + 1000);
	fuelbar->position = Point2(0, 30);
	fuelbar->scale.x = plane->fuel;
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
	this->addChild(scoreText);


	scoreText->position = Point2(SWIDTH / 2.0f - 605, SHEIGHT / 2.0f - 275);

	asteroid->physicsBody->SetGravityScale(0);
	coin->physicsBody->SetGravityScale(0);
	fuel->physicsBody->SetGravityScale(0);

	asteroid->physicsBody->SetLinearVelocity(b2Vec2(-20, 1));
	asteroid->physicsBody->SetAngularVelocity(2);

	coin->physicsBody->SetLinearVelocity(b2Vec2(-10, 0));
	fuel->physicsBody->SetLinearVelocity(b2Vec2(-5, 0));

	shootTimer.start();
}

MyScene::~MyScene()
{
	delete collisionHandler;
	physicsWorld->SetContactListener(NULL);

	this->removeChild(scoreText);
	this->removeChild(asteroid);
	this->removeChild(fuelbar);
	this->removeChild(hudobject);
	this->removeChild(coin);
	this->removeChild(background);
	this->removeChild(plane);
	this->removeChild(warningSprite);

	for (MyBullet* b : bullets) {
		this->removeChild(b);
		delete b;
	}
	bullets.clear();

	delete scoreText;
	delete hudobject;
	delete asteroid;
	delete plane;
	delete fuelbar;
	delete coin;
	delete background;
	delete warningSprite;
	delete physicsWorld;
}

void MyScene::update(float deltaTime)
{
	std::stringstream scoreStream;
	scoreStream << "Points: ";
	scoreStream << points;
	scoreText->message(scoreStream.str(), WHITE);
	fuelbar->scale.x = plane->fuel;
	physicsWorld->Step(deltaTime, 8, 5);
	startFlyingcount += deltaTime;
	warningSprite->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	fuel->physicsBody->SetAngularVelocity(0);
	coin->physicsBody->SetAngularVelocity(0);

	if (plane->position.y < 0 || plane->position.y > 1080) {
		outscreenTimer += deltaTime;
	}
	else
	{
		outscreenTimer = 0;
	}

	if (outscreenTimer >= 2.0f) {
		this->stop();
	}
	if (plane->fuel > 81) {
		plane->fuel = 81;
	}
	if (input()->getMouseDown(0))
	{
		plane->shoot();
	}
	if (plane->setBackCoin) {
		Point2 currentPositionC = coin->position;
		currentPositionC.x = 1600 * 0.02f;
		currentPositionC.y = rand() % 700 * 0.02f;
		coin->physicsBody->SetTransform(b2Vec2(currentPositionC.x, currentPositionC.y), coin->rotation);
		coin->physicsBody->SetLinearVelocity(b2Vec2(-10, 0));
		points += 1;
		std::cout << points << std::endl;

		plane->setBackCoin = false;
	}
	if (plane->setBackFuel) {
		Point2 currentPositionF = fuel->position;
		currentPositionF.x = 1600 * 0.02f;
		currentPositionF.y = rand() % 700 * 0.02f;
		fuel->physicsBody->SetTransform(b2Vec2(currentPositionF.x, currentPositionF.y), fuel->rotation);
		fuel->physicsBody->SetLinearVelocity(b2Vec2(-10, 0));
		plane->setBackFuel = false;
	}
	if (plane->checkAsteroid) {

		this->stop();
		plane->checkAsteroid = false;
	}
	if (coin->position.x < 0) {
		Point2 currentPositionCX = coin->position;
		currentPositionCX.x = 1600 * 0.02f;
		currentPositionCX.y = rand() % 700 * 0.02f;
		coin->physicsBody->SetTransform(b2Vec2(currentPositionCX.x, currentPositionCX.y), coin->rotation);
		coin->physicsBody->SetLinearVelocity(b2Vec2(-10, 0));
	}
	if (coin->position.y < 0 || coin->position.y > 1080) {
		Point2 currentPositionCY = coin->position;
		currentPositionCY.x = 1600 * 0.02f;
		currentPositionCY.y = rand() % 700 * 0.02f;
		coin->physicsBody->SetTransform(b2Vec2(currentPositionCY.x, currentPositionCY.y), coin->rotation);
		coin->physicsBody->SetLinearVelocity(b2Vec2(-10, 0));
	}
	if (fuel->position.x < 0) {
		Point2 currentPositionFX = fuel->position;
		currentPositionFX.x = 1600 * 0.02f;
		currentPositionFX.y = rand() % 700 * 0.02f;
		fuel->physicsBody->SetTransform(b2Vec2(currentPositionFX.x, currentPositionFX.y), fuel->rotation);
		fuel->physicsBody->SetLinearVelocity(b2Vec2(-5, 0));

	}
	if (fuel->position.y < 0 || fuel->position.y > 1080) {
		Point2 currentPositionFY = fuel->position;
		currentPositionFY.x = 1600 * 0.02f;
		currentPositionFY.y = rand() % 700 * 0.02f;
		fuel->physicsBody->SetTransform(b2Vec2(currentPositionFY.x, currentPositionFY.y), fuel->rotation);
		fuel->physicsBody->SetLinearVelocity(b2Vec2(-5, 0));

	}
	if (asteroid->position.x < 0) {
		Point2 currentPositionAX = asteroid->position;
		currentPositionAX.x = 1600 * 0.02f;
		currentPositionAX.y = rand() % 700 * 0.02f;
		asteroid->physicsBody->SetTransform(b2Vec2(currentPositionAX.x, currentPositionAX.y), asteroid->rotation);
		asteroid->physicsBody->SetLinearVelocity(b2Vec2(-20, rand() % 10));
	}
	if (asteroid->position.y < 0 || asteroid->position.y > 1080) {
		Point2 currentPositionAY = asteroid->position;
		currentPositionAY.x = 1600 * 0.02f;
		currentPositionAY.y = rand() % 700 * 0.02f;
		//asteroid->physicsBody->SetTransform(b2Vec2(currentPositionAY.x, currentPositionAY.y), asteroid->rotation);
		//asteroid->physicsBody->SetLinearVelocity(b2Vec2(-5, 0));

	}
	if (fuelbar->scale.x < 0) {
		startFlying = false;
	}

	if (!startFlying) {
		plane->physicsBody->SetGravityScale(0);
		plane->physicsBody->SetTransform(plane->physicsBody->GetPosition(), 0);
		if (startFlyingcount > 1) {
			startFlying = true;
			plane->physicsBody->SetGravityScale(3);
		}
	}

	if (input()->getKeyDown(GLFW_KEY_LEFT_SHIFT) && shootTimer.seconds() > 5.0f) {
		shoot();
		shootTimer.stop();
		shootTimer.start();
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

	std::vector<MyBullet*>::iterator it = bullets.begin();
	while (it != bullets.end()) {
		if ((*it)->destroyMe) {
			(*it)->destroyMe = true;
			it = bullets.erase(it);
		}
		else {
			it++;
		}
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

void MyScene::shoot()
{
	MyBullet* b = new MyBullet();
	bullets.push_back(b);
	b->position = plane->position + Point2(50, 0);
	b->createPhysics(physicsWorld, Vector2(128, 32));
	b->physicsBody->SetGravityScale(0);
	b->physicsBody->SetLinearVelocity(b2Vec2(b->bulletSpeed, 0));
	physicsEntities.push_back(b);
	this->addChild(b);
}
