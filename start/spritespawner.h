#ifndef MYSPRITE_H
#define MYSPRITE_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class MySprite : public Entity
{
public:
	/// @brief Constructor
	MySprite();
	/// @brief Destructor
	virtual ~MySprite();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif
