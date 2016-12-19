#pragma once
#include "Laser.h"


class nvoLaser : public Laser{
private:
	int direction;

public:

	//constructeur avec parametre
	nvoLaser(int direction);

	//constructeur sana parametre
	nvoLaser();

	//m�thodes sp�cifiques

	//initialiser laser
	void enclencherLaser(int x, int y, int direction);

	//deplacer laser
	virtual void bougeLaser(int direction);

	//mettre le laser
	void putLaser() const;

	//tester collision
	bool collision(int posX, int posY);
};