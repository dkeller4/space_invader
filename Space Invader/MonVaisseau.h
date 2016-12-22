#pragma once

#include "Vaisseau.h"
#include "Laser.h"
#include "Timer.h"
#include "DFLaser.h"
#include "miniMartien.h"

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
	int vies= 4;
	DFLaser tabLasers[MAX_LASERS];
	MonVaisseau();

	void setvaisseauAlien();

	DFLaser* getTabLasers();
	Timer delaiTir;
	void tirerLaser();
	void tirerUnLaser();
	int nombreDeLaser() const;
	bool collision(int posX, int posY);
	void putVaisseau(bool touche) const;
	void modifierPosition(char key);
	void removeVaisseau() const;
	void gestionLaserAliens(int maxLaser, int nb_aliens, const miniMartien* aliens);
};