/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef FUEL_H
#define FUEL_H

#include <start/JeffreyEntity.h>

 /// @brief The MyEntity class is the Entity implementation.
class Fuel : public MyJeffreyEntity
{
public:
	/// @brief Constructor
	Fuel();
	/// @brief Destructor
	virtual ~Fuel();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	int pickUp();
private:
	/* add your private declarations */
	int fuelAmmount;
};

#endif /* MYENTITY_H */
