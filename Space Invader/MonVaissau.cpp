#include "MonVaissau.h"
#include "Vaisseau.h"
#include "Laser.h"
#include "Timer.h"

#include "UIKit.h"

#include <Windows.h>
#include <conio.h>

#include <iostream>
#include <string>
using namespace std;

// Methode privée
void MonVaissau::gestionLaser(int debutLaser, int maxLaser, int posXOffset) {
	int i = debutLaser;
	while (i < maxLaser && tabLasers[i].isAlive == true)
		i++;

	if (i < maxLaser) {		//	une case avec un laser 'mort' ?
		tabLasers[i].enclencherLaser(coord.getPositionX() + posXOffset, coord.getPositionY(), -1);
		tabLasersTimer[i].setDelai(DELAI_LASER);
	}

	if (i < maxLaser) {		//	une case avec un laser 'mort' ?
		tabLasers[i].enclencherLaser(coord.getPositionX() + posXOffset, coord.getPositionY(), -1);
		tabLasersTimer[i].setDelai(DELAI_LASER);
	}
}

// Constructeur
MonVaissau::MonVaissau() {
	// Position initial du vaissau
	coord.setPositionX(INIT_POS_X);
	coord.setPositionY(INIT_POS_Y);
	// affichage du vaissau
	leVaissau = "(^_^)";
	putVaisseau();
	//	iniitialisation des lasers
	for (int i = 0; i < MAX_LASERS; i++)
		tabLasers[i].isAlive = false;
}

nvoLaser* MonVaissau::getTabLasers() {
	return tabLasers;
}

void MonVaissau::tirerSingleLaser() {
	gestionLaser(0, MAX_LASERS, 2);
}

// Methodes public
void MonVaissau::tirerDoubleLaser() {
	gestionLaser(0, MAX_DOUBLE_LASERS / 2, 0);
	gestionLaser(MAX_DOUBLE_LASERS / 2, MAX_DOUBLE_LASERS, 4);
}

// tire un laser
void MonVaissau::tirerLaser() {
	//	gestion du clavier
	if (_kbhit()) {			//	une touche est prête ?
		char touche = _getch();		//	on la prend du tampon

		// Si le clavier de control est utilise
		if (touche == 224)
		{
			touche = _getch();
		}

		//	gestion vaisseau
		modifierPosition(touche);

		//	gestion d'un nouveau tir de laser
		if (touche == ' ') {
			// laser simple
			tirerSingleLaser();
		}
		else if (touche == 'd' || touche == 'D') {
			// double lasers
			tirerDoubleLaser();
		}
	}

	//	gestion des lasers
	for (int i = 0; i < MAX_LASERS; i++) {
		if (tabLasers[i].isAlive && tabLasersTimer[i].tempsEcoule())
			tabLasers[i].bougeLaser(-1);
	}
}

// Test de collision
bool MonVaissau::collision(int posX, int posY) {
	return (posX >= coord.getPositionX() && posX <= coord.getPositionX() + (int)leVaissau.length() - 1
		&& coord.getPositionY() == posY);
}

int MonVaissau::decompteLaser() const {
	//	décompte des lasers
	int cpt = 0;
	for (int i = 0; i < MAX_LASERS; i++)
		if (tabLasers[i].isAlive)
			cpt++;

	return cpt;
}

void MonVaissau::putVaisseau() const
{
	UIKit::color(0x0007 + 0x0008);
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());

	cout << leVaissau;
}

void MonVaissau::modifierPosition(char key)
{
	removeVaisseau();
	switch (key)
	{
	case 'k':
		// Test de colision avec le cadre de gauche
		if (coord.getPositionX() > BORDURE_POS_X_GAUCHE)
			coord.setPositionX(coord.getPositionX() - 1);
		break;
	case 'l':
		// Test de colision avec le cadre de droite
		if (coord.getPositionX() < BORDURE_POS_X_DROITE)
			coord.setPositionX(coord.getPositionX() + 1);
	}
	putVaisseau();
}

void MonVaissau::removeVaisseau() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << "      ";
}