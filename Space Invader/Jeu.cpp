#include "Jeu.h"
#include "UIKit.h"
#include "Timer.h"
#include <time.h>
#include <string>
#include <iostream>
#include "ExtraTerrestre.h"
#include "miniMartien.h"
using namespace std;


void Jeu::debut() {
	gameOver = true;
	MortVaisseau = false;
	MortMiniMartienJaune = false;
	MortMiniMartienRouge = false;
	score = 0;
}

// Constructeur
Jeu::Jeu() {
	debut();

}
void Jeu::affichageDuTerrain() const {
	system("cls");
	ecran.curseurVisible(false);
	//Taille de la fenetre
	ecran.setDimensionFenetre(0, 0, nbColonnesTerrain + 30, nbLignesTerrain + 30);
	// zone informations sur le terrain de jeu
	ecran.cadre(0, 0, nbColonnesTerrain, nbLignesTerrain, FOREGROUND_YELLOW + FOREGROUND_INTENSITY);



	//zone informations sur le jeu
	ecran.cadre(nbColonnesTerrain + 2, 0, nbColonnesTerrain + 1 + 28, 51, FOREGROUND_RED + FOREGROUND_INTENSITY);
	ecran.color(FOREGROUND_YELLOW + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 9, 7);
	cout << "INFOS GAME";


	ecran.color(FOREGROUND_CYAN + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 10, 14);
	cout << "COINS: ";


	ecran.color(FOREGROUND_RED + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 3, 16);
	cout << "MiniMartiensR: " << " COINS";

	ecran.color(FOREGROUND_BLUE + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 3, 18);
	cout << "MiniMartiensB: " << " COINS";

	ecran.color(FOREGROUND_GREEN + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 3, 20);
	cout << "MiniMartiensG: " << " COINS";


	ecran.color(FOREGROUND_CYAN + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 10, 22);
	cout << "Score:";


	ecran.color(FOREGROUND_YELLOW + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 12, 25);
	cout << score;

}

void Jeu::demarrerLeJeu() {

	gameOver = false;
	affichageDuTerrain();
	// chargement du son
	PlaySound(TEXT("laser.mid"), NULL, SND_MEMORY);

	// pour faire apparaitre le vaisseau
	sangomar.modifierPosition(75);

	// pour faire apparaitre les miniMartiens
	ligneExtraTerrestres(10, 8, 3);
	ligneExtraTerrestres(15, 10, 4);
	
	

	
	do {
		//	le vaisseau tire
		sangomar.tirerLaser();

		

		testerLaCollision();

		if (MortVaisseau)
			gameOver = true;

		//Sleep(100);

	} while (!gameOver);

	if (MortVaisseau)
		GameOver();
}

// Methodes public

//test de collision
void Jeu::testerLaCollision()
{
	aliens[]

		MonVaisseau.tabLaser



		aliens[2].supprimerExtraterrestre();
}

void Jeu::GameOver() {
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

void Jeu::Victoire() {
	//	effet d'effacement
	system("cls");
	ecran.color(FOREGROUND_WHITE + FOREGROUND_INTENSITY);
	UIKit::gotoXY(0, 20);
	cout << "VICTOIRE!!!!" << endl;
	UIKit::gotoXY(0, 25);
	for (int i = 0; i < 50; i++) {
		cout << endl;
		Sleep(70);
	}
}

void Jeu::reinitialiserLejeu() {
	system("cls");
	debut();
}

void Jeu::affichageScore() {
	// affiche le score du combat
	ecran.color(FOREGROUND_YELLOW + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 2, 3);
	cout << "            ";
	ecran.gotoXY(nbColonnesTerrain + 1 + 2, 3);
	cout << score;
}

void Jeu::ligneExtraTerrestres(int position_y, int nombre_aliens, int depart) {
	for (int i = _nb_aliens; i < _nb_aliens + nombre_aliens; i++) {
		aliens[i].setMiniMartien( depart + (i - _nb_aliens) * nbColonnesTerrain/(nombre_aliens), position_y, (i % 3) + 1);
		aliens[i].dessinerExtraTerrestre();
	}
	_nb_aliens += nombre_aliens;
}