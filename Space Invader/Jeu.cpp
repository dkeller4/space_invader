#include "Jeu.h"
#include "UIKit.h"
#include "Timer.h"
#include <time.h>
#include <fstream>
#include <string>
#include <iostream>
#include "ExtraTerrestre.h"
#include "miniMartien.h"
using namespace std;


void Jeu::debut() {
	finDeJeu = true;
	vaissauEstMort = false;
	unVenusienEstMort = false;
	unSaturnienEstMort = false;
	score = 0;
}

// Constructeur
Jeu::Jeu() {
	debut();
}

void Jeu::startGame() {

	finDeJeu = false;
	afficherTerrain();

	// pour faire apparaitre le vaissau
	sangomar.modifierPosition(75);

	// pour faire apparaitre les miniMartiens
	miniMartien * aliensLigne1 = apparitionExraTerrestres(10);
	miniMartien * aliensLigne2 = apparitionExraTerrestres(20);


	
	do {
		//	le vaissau tire
		sangomar.tirerLaser();

		

		testCollision();

		if (vaissauEstMort)
			finDeJeu = true;

		//Sleep(100);

	} while (!finDeJeu);

	if (vaissauEstMort)
		afficherGameOver();
}

// Methodes public
miniMartien * Jeu::apparitionExraTerrestres(int y) {
	miniMartien aliens[8];

	for (int i = 0; i < 8; i++) {
		aliens[i].setMiniMartien( (y/3 + i * 8), y, (i % 3)+1);
		aliens[i].dessinerExtraTerrestre();
	}

	return aliens;
}

//test de collision
void Jeu::testCollision()
{
	
}

void Jeu::afficherGameOver() {
	//	effet d'effacement
	system("cls");
	ecran.color(FOREGROUND_RED + FOREGROUND_INTENSITY);
	UIKit::gotoXY(0, 20);
	cout << "GAME OVER.....!!!" << endl;
	UIKit::gotoXY(0, 25);
	for (int i = 0; i < 50; i++) {
		cout << endl;
		Sleep(70);
	}
}

void Jeu::afficherVictoire() {
	//	effet d'effacement
	system("cls");
	ecran.color(FOREGROUND_BLUE + FOREGROUND_INTENSITY);
	UIKit::gotoXY(0, 20);
	cout << "VICTOIRE!!!!" << endl;
	UIKit::gotoXY(0, 25);
	for (int i = 0; i < 50; i++) {
		cout << endl;
		Sleep(70);
	}
}


void Jeu::afficherTerrain() const {
	// Clear consoles
	system("cls");

	// Cache le curseur
	ecran.curseurVisible(false);

	// Initialise les dimensions de la fenetre
	ecran.setDimensionFenetre(0, 0, nbColonnesTerrain + 30, nbLignesTerrain + 30);

	// Creer le cadre du terrain de jeu
	ecran.cadre(0, 0, nbColonnesTerrain, nbLignesTerrain, FOREGROUND_YELLOW + FOREGROUND_INTENSITY);

	// Creer le cadre info jeu (type extraterrstres + scores)
	ecran.cadre(nbColonnesTerrain + 1, 0, nbColonnesTerrain + 1 + 25, 15, FOREGROUND_RED + FOREGROUND_INTENSITY);

	
	ecran.color(FOREGROUND_CYAN + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 2, 5);
	cout << "COINS : ";
	ecran.color(FOREGROUND_YELLOW + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 2, 6);
	cout << "Venusien : " << " COINS";
	ecran.gotoXY(nbColonnesTerrain + 1 + 2, 7);
	cout << "Saturnien : " << " COINS";
	ecran.color(FOREGROUND_YELLOW + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 2, 2);
	cout << "Score : ";
	ecran.color(FOREGROUND_WHITE + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 2, 3);
	cout << score;

}

void Jeu::resetGame() {
	system("cls");
	debut();
}

void Jeu::afficherScore() {
	// affiche le score du combat
	ecran.color(FOREGROUND_YELLOW + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 2, 3);
	cout << "            ";
	ecran.gotoXY(nbColonnesTerrain + 1 + 2, 3);
	cout << score;
}