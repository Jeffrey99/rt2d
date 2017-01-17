/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef ASTEROID_H
#define ASTEROID_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class Asteroid : public Entity
{
public:
	/// @brief Constructor
	Asteroid();
	/// @brief Destructor
	virtual ~Asteroid();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
	float turnspeed = rand() % 300;
};

#endif /* MYENTITY_H */
