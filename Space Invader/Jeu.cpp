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

// Methodes priv�es
void Jeu::lireFichier(const string & monfichier) {
	// Ouvrir un fichier
	ifstream fichier(monfichier.c_str());

	if (fichier) {
		string ligne;
		while (getline(fichier, ligne)) {
			cout << ligne << endl;
		}
	}

}

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

	// Dessiner les extraterrestres par ligne
	/*miniMartien* monstresLigne1 = dessinerLigneExtraterrestres(5, 10);
	miniMartien* monstresLigne2 = dessinerLigneExtraterrestres(10, 15);
	miniMartien* monstresLigne2 = dessinerLigneExtraterrestres(7, 20);*/
	

	sangomar.tirerLaser();
	
	do {
		//	le vaisseau tire
		sangomar.tirerLaser();

		testCollision();

		if (vaissauEstMort)
			finDeJeu = true;

		Sleep(100);

	} while (!finDeJeu);

	if (vaissauEstMort)
		afficherGameOver();
}

// Methodes public
void Jeu::apparitionExraTerrestres() {

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
	lireFichier(fichierGameOver);

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
	lireFichier(fichierVictoire);

	UIKit::gotoXY(0, 25);
	for (int i = 0; i < 50; i++) {
		cout << endl;
		Sleep(70);
	}
}

void Jeu::afficherTitreJeu() {
	// Affiche le tire du jeu en lisant des fichiers
	ecran.color(FOREGROUND_BLUE + FOREGROUND_INTENSITY);
	ecran.color(FOREGROUND_GREEN + FOREGROUND_INTENSITY);
	lireFichier(fichierTitre);
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
	ecran.cadre(nbColonnesTerrain + 1, 0, nbColonnesTerrain + 1 + 25, 15, FOREGROUND_RED);

	
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
	ecran.color(FOREGROUND_BLUE + FOREGROUND_INTENSITY);
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