/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef MYBULLET_H
#define MYBULLET_H

#include <start/JeffreyEntity.h>

/// @brief The MyEntity class is the Entity implementation.
class MyBullet : public MyJeffreyEntity
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
	virtual void onCollisionEnter(MyJeffreyEntity* entity);
	virtual void onCollisionExit(MyJeffreyEntity* entity);

private:
	/* add your private declarations */
	float bulletSpeed;
	float destroyTime;
};

#endif /* MYBULLET_H */
