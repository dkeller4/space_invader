#pragma once

#include "Vaisseau.h"
#include "Laser.h"
#include "Timer.h"
#include "DFLaser.h"

#include <string>
using namespace std;

#define BORDURE_POS_X_DROITE 64
#define BORDURE_POS_X_GAUCHE 1

#define INIT_POS_X 20
#define INIT_POS_Y 40

#define MAX_LASERS 40
#define MAX_DOUBLE_LASERS 10
#define DELAI_LASER 45

class MonVaisseau : public Vaisseau
{
private:
	Timer tabLasersTimer[MAX_LASERS];
	string leVaissau;

	void gestionLaser(int debutLaser, int maxLaser, int posXOffset);

public:
	DFLaser tabLasers[MAX_LASERS];
	MonVaisseau();

	DFLaser* getTabLasers();

	void tirerLaser();
	void tirerUnLaser();
	int nombreDeLaser() const;
	bool collision(int posX, int posY);
	void putVaisseau() const;
	void modifierPosition(char key);
	void removeVaisseau() const;
};