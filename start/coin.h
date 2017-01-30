#ifndef COIN_H
#define COIN_H

#include <start/JeffreyEntity.h>

class MyCoin : public MyJeffreyEntity
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
