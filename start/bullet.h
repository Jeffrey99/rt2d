/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef MYBULLET.H
#define MYBULLET.H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class MyBullet : public Entity
{
public:
	/// @brief Constructor
	MyBullet();
	/// @brief Destructor
	virtual ~MyBullet();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYBULLET_H */
