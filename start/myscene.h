/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include <Box2D/Box2D.h>
#include "plane.h"
#include "spritespawner.h"
#include "background.h"
#include "coin.h"
#include "hud.h"
#include "asteroid.h"
#include "fuel.h"


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
	b2Body* blokje1;
private:
	/// @brief the rotating square in the middle of the screen
	MyPlane* plane;
	MySprite* warningSprite;
	MyCoin* coin;
	MyBackground* background;
	MyHud* hudobject;
	Asteroid* asteroid;
	bool startFlying;
	float startFlyingcount;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* SCENE00_H */
