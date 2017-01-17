#ifndef MYPLANE_H
#define MYPLANE_H

#include <rt2d/entity.h>

class MyPlane : public Entity
{
public:
	/// @brief Constructor
	MyPlane();
	/// @brief Destructor
	virtual ~MyPlane();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
public:
	/* add your public declarations */

};

#endif
