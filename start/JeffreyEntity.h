/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef MYJEFFREYENTITY_H
#define MYJEFFREYENTITY_H

#include <string>

#include <rt2d/entity.h>
#include <Box2D/Box2D.h>


/// @brief The MyEntity class is the Entity implementation.
class MyJeffreyEntity : public Entity
{
public:
	/// @brief Constructor
	MyJeffreyEntity();
	/// @brief Destructor
	virtual ~MyJeffreyEntity();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	b2Body* physicsBody;
	Vector2 collidersize;
	void createPhysics(b2World* rootWorld, Vector2 collidersize);
	virtual void onCollisionEnter(MyJeffreyEntity* entity);
	virtual void onCollisionExit(MyJeffreyEntity* entity);

	std::string name;
	bool destroyMe;
private:

	b2World* rootWorld;

};

#endif /* MYENTITY_H */
