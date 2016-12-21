#pragma once
#include "Laser.h"


class DFLaser : public Laser{
private:
	int direction;
public:
	DFLaser();
	DFLaser(int direction);
	virtual void moveLaser(int direction);
	void initLaser(int x, int y, int direction);
	void putLaser() const;
	bool collision(int posX, int posY);
};