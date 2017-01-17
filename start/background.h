#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <rt2d/entity.h>

class MyBackground : public Entity
{
public:
	MyBackground();
	virtual ~MyBackground();


	virtual void update(float deltaTime);

private:
	/* add your private declarations */
public:
	/* add your public declarations */

};

#endif
