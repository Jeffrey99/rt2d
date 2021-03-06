/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <sstream>
#include <rt2d/scene.h>
#include <rt2d/text.h>
#include <Box2D/Box2D.h>
#include "plane.h"
#include "spritespawner.h"
#include "background.h"
#include "coin.h"
#include "hud.h"
#include "asteroid.h"
#include "fuel.h"
#include "bullet.h"
#include "collisionhandler.h"




 /// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	b2World* physicsWorld;

private:
	/// @brief the rotating square in the middle of the screen
	void checkEntitiesToDestroy();
	MyPlane* plane;
	MySprite* warningSprite;
	MySprite* fuelbar;
	MyCoin* coin;
	MyBackground* background;
	MyHud* hudobject;
	Asteroid* asteroid;
	Fuel* fuel;
	CollisionHandler* collisionHandler;
	bool startFlying;
	Timer shootTimer;
	float startFlyingcount;
	float outscreenTimer;
	int points;
	std::vector<MyJeffreyEntity*> physicsEntities;
	Text* scoreText;

	std::vector<MyBullet*> bullets;
	void shoot();

};

#endif /* SCENE00_H */
