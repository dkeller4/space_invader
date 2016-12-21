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
	ecran.cadre(nbColonnesTerrain + 2, 0, nbColonnesTerrain + 1 + 28, 15, FOREGROUND_RED + FOREGROUND_INTENSITY);
	ecran.color(FOREGROUND_RED + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 7, 2);
	cout << "INFOS GAME";
	ecran.color(FOREGROUND_CYAN + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 8, 5);
	cout << "COINS: ";
	ecran.color(FOREGROUND_YELLOW + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 3, 8);
	cout << "MiniMartiensR: " << " COINS";
	ecran.gotoXY(nbColonnesTerrain + 1 + 3, 7);
	cout << "MiniMartiensJ: " << " COINS";
	ecran.color(FOREGROUND_CYAN + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 8, 10);
	cout << "Score:";
	ecran.color(FOREGROUND_YELLOW + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 10, 12);
	cout << score;

}

void Jeu::demarrerLeJeu() {

	gameOver = false;
	affichageDuTerrain();

	// pour faire apparaitre le vaissau
	sangomar.modifierPosition(75);

	// pour faire apparaitre les miniMartiens
	miniMartien * aliensLigne1 = apparitionExraTerrestres(10);
	miniMartien * aliensLigne2 = apparitionExraTerrestres(20);


	
	do {
		//	le vaissau tire
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
miniMartien * Jeu::apparitionExraTerrestres(int y) {
	miniMartien aliens[8];

	for (int i = 0; i < 8; i++) {
		aliens[i].setMiniMartien( (y/3 + i * 8), y, (i % 3)+1);
		aliens[i].dessinerExtraTerrestre();
	}

	return aliens;
}

//test de collision
void Jeu::testerLaCollision()
{
	
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