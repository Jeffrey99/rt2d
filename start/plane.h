#ifndef MYPLANE_H
#define MYPLANE_H

#include <sstream>
#include <start/JeffreyEntity.h>
#include <start/fuel.h>

class MyPlane : public MyJeffreyEntity
{
public:
	/// @brief Constructor
	MyPlane();
	/// @brief Destructor
	virtual ~MyPlane();
	virtual void onCollisionEnter(MyJeffreyEntity* entity);
	virtual void onCollisionExit(MyJeffreyEntity* entity);

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	int fuel;
private:
	/* add your private declarations */
public:
	/* add your public declarations */
	void shoot();


};

#endif
