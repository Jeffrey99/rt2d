#ifndef COIN_H
#define COIN_H

#include <rt2d/entity.h>

class MyCoin : public Entity
{
public:
	MyCoin();
	virtual ~MyCoin();


	virtual void update(float deltaTime);

private:
	/* add your private declarations */
public:
	/* add your public declarations */

};

#endif
