#pragma once

#include <Box2D/Dynamics/b2WorldCallbacks.h>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/Contacts/b2Contact.h>
#include <iostream>
#include <vector>
#include <start/JeffreyEntity.h>

class CollisionHandler : public b2ContactListener
{
public:
	CollisionHandler(std::vector<MyJeffreyEntity*>* entities);
	~CollisionHandler();

	void BeginContact(b2Contact* contact);

	void EndContact(b2Contact* contact);

private:
	std::vector<MyJeffreyEntity*>* entities;
	MyJeffreyEntity* getEntityFromBody(b2Body* body);
};