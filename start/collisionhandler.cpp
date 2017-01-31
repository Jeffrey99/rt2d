#include <rt2d/collisionhandler.h>

CollisionHandler::CollisionHandler(std::vector<MyJeffreyEntity*>* entities) : b2ContactListener()
{
	this->entities = entities;
}


CollisionHandler::~CollisionHandler()
{

}

void CollisionHandler::BeginContact(b2Contact* contact)
{
	MyJeffreyEntity* entityA;
	MyJeffreyEntity* entityB;

	entityA = getEntityFromBody(contact->GetFixtureA()->GetBody());
	entityB = getEntityFromBody(contact->GetFixtureB()->GetBody());

	if (entityA != NULL && entityB != NULL)
	{
		entityA->onCollisionEnter(entityB);
		entityB->onCollisionEnter(entityA);
	}
}

void CollisionHandler::EndContact(b2Contact* contact)
{
	MyJeffreyEntity* entityA;
	MyJeffreyEntity* entityB;
	entityA = getEntityFromBody(contact->GetFixtureA()->GetBody());
	entityB = getEntityFromBody(contact->GetFixtureB()->GetBody());
	if (entityA != NULL && entityB != NULL)
	{
		entityA->onCollisionExit(entityB);
		entityB->onCollisionExit(entityA);
	}
}

MyJeffreyEntity* CollisionHandler::getEntityFromBody(b2Body* body)
{
	std::vector< MyJeffreyEntity* >::iterator it = entities->begin();
	while (it != entities->end())
	{
		if (body == (*it)->physicsBody) {
			return (*it);
		}
		it++;
	}
	return NULL;
}