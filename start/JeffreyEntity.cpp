/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "JeffreyEntity.h"

MyJeffreyEntity::MyJeffreyEntity() : Entity()
{
	physicsBody = NULL;
	name = "Unnamed";
	destroyMe = false;
}

MyJeffreyEntity::~MyJeffreyEntity()
{
	rootWorld->DestroyBody(physicsBody);
}

void MyJeffreyEntity::update(float deltaTime)
{
	this->position = Point2(physicsBody->GetPosition().x, physicsBody->GetPosition().y) * 50.0f;
	this->rotation = physicsBody->GetAngle();
}

void MyJeffreyEntity::createPhysics(b2World * rootWorld, Vector2 collidersize)
{
	this->collidersize = collidersize;
	this->rootWorld = rootWorld;
	b2BodyDef bodyDef;
	bodyDef.position.Set(this->position.x * 0.02f, this->position.y * 0.02f);
	bodyDef.type = b2_dynamicBody;
	this->physicsBody = rootWorld->CreateBody(&bodyDef);

	b2PolygonShape shape;

	shape.SetAsBox(collidersize.x * 0.02f, collidersize.y * 0.02f);

	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1.0f;
	fixture.isSensor = true;


	this->physicsBody->CreateFixture(&fixture);
}

void MyJeffreyEntity::onCollisionEnter(MyJeffreyEntity * entity)
{
}

void MyJeffreyEntity::onCollisionExit(MyJeffreyEntity * entity)
{
}

