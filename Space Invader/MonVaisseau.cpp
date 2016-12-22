#include "MonVaisseau.h"
#include "Vaisseau.h"
#include "Laser.h"
#include "Timer.h"

#include "UIKit.h"

#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>

#include <iostream>
#include <string>
using namespace std;

#define FOREGROUND_CYAN 0x0003

// Methode priv�e
void MonVaisseau::gestionLaser(int debutLaser, int maxLaser, int milieu_vaisseau) {
	int i = debutLaser;

	// on recherche l'indice du nouveau laser
	while (i < maxLaser && tabLasers[i].isAlive == true)
		i++;

	if (i < maxLaser) {		//	une case avec un laser
		tabLasers[i].initLaser(coord.getPositionX() + milieu_vaisseau, coord.getPositionY(), -1);
		tabLasersTimer[i].setDelai(DELAI_LASER);
	}

	if (i < maxLaser) {		// deuxieme case pour avoir un laser plus long
		tabLasers[i].initLaser(coord.getPositionX() + milieu_vaisseau, coord.getPositionY(), -1);
		tabLasersTimer[i].setDelai(DELAI_LASER);
	}
}

// Constructeur
MonVaisseau::MonVaisseau() {
	// Position initial du vaisseau
	coord.setPositionX(INIT_POS_X);
	coord.setPositionY(INIT_POS_Y);
	// affichage du vaisseau
	leVaissau = "(^_^)";
	putVaisseau();
	//	initialisation des lasers
	for (int i = 0; i < MAX_LASERS; i++)
		tabLasers[i].isAlive = false;
}

DFLaser* MonVaisseau::getTabLasers() {
	return tabLasers;
}

void MonVaisseau::tirerUnLaser() {
	gestionLaser(0, MAX_LASERS, 2);
}

// tire un laser
void MonVaisseau::tirerLaser() {
	//	gestion du clavier
	if (_kbhit()) {			//	une touche est pr�te ?
		char touche = _getch();		//	on la prend du tampon

		//// Si le clavier de control est utilise
		//if (touche == 224)
		//{
		//	touche = _getch();
		//}

		//	gestion vaisseau
		modifierPosition(touche);

		//	gestion d'un nouveau tir de laser
		if (touche == ' ') {

			// laser simple
			tirerUnLaser();
			
			
			// Jouer 1x le son laser.wav
			//PlaySound(TEXT("laser.mid"), NULL, SND_SYNC);
		}
		
	}

	//	gestion des lasers
	for (int i = 0; i < MAX_LASERS; i++) {
		if (tabLasers[i].isAlive && tabLasersTimer[i].tempsEcoule())
			tabLasers[i].moveLaser(-1);
	}
}

// Test de collision
bool MonVaisseau::collision(int posX, int posY) {
	return (posX >= coord.getPositionX() && posX <= coord.getPositionX() + (int)leVaissau.length() - 1
		&& coord.getPositionY() == posY);
}

int MonVaisseau::nombreDeLaser() const {
	//	d�compte des lasers
	int cpt = 0;
	for (int i = 0; i < MAX_LASERS; i++)
		if (tabLasers[i].isAlive)
			cpt++;

	return cpt;
}

void MonVaisseau::putVaisseau() const
{
	UIKit::color(FOREGROUND_CYAN + FOREGROUND_INTENSITY);
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << leVaissau;
}

void MonVaisseau::modifierPosition(char key)
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

void MonVaisseau::removeVaisseau() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << "      ";
}

