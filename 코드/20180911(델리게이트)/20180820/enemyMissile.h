#pragma once
#include "missile.h"

class enemyMissile : public missile
{
public:
	virtual void move() override;

	enemyMissile();
	~enemyMissile();
};

