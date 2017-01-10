/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class MyBackground : public Entity
{
public:
	/// @brief Constructor
	MyBackground();
	/// @brief Destructor
	virtual ~MyBackground();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
public:
	/* add your public declarations */

};

#endif /* MYENTITY_H */
