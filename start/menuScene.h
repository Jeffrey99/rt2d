/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <rt2d/scene.h>
#include "spritespawner.h"


/// @brief The MyScene class is the Scene implementation.
class MyMenuScene : public Scene
{
public:
	/// @brief Constructor
	MyMenuScene();
	/// @brief Destructor
	virtual ~MyMenuScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen
	/// @brief a Timer to rotate the color every n seconds
	MySprite* background;
	Timer t;
};

#endif /* SCENE00_H */
