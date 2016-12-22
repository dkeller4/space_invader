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
	cout << "MiniMartiensR: " << "5 COINS";

	ecran.color(FOREGROUND_BLUE + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 3, 18);
	cout << "MiniMartiensB: " << "10 COINS";

	ecran.color(FOREGROUND_GREEN + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 3, 20);
	cout << "MiniMartiensG: " << "15 COINS";


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
	ligneExtraTerrestres(15, 5, 5);
	
	

	
	do {
		//	le vaisseau tire
		sangomar.tirerLaser();

		
		// tester les collisions
		testerLaCollision();
	
		jiggle();

		if (MortVaisseau)
			gameOver = true;

		//Sleep(100);

	} while (!gameOver);

	if (MortVaisseau)
		GameOver();
}

// Methodes public

// faire bouger les aliens de la premiere ligne
void Jeu::jiggle() {

	if (delaiJiggle.tempsEcoule()) {

		// pour la premiere ligne on les fait faire un mouvement droite-gauche
		for (int i = 0; i < 8; i++) {

			if (aliens[i].isAlive) {
				aliens[i].effacerExtraTerrestre();

				if (aliens[i].jiggle) {
					aliens[i].coord.setPositionX(aliens[i].coord.getPositionX() - 1);
				}
				else {
					aliens[i].coord.setPositionX(aliens[i].coord.getPositionX() + 1);
				}
				aliens[i].jiggle = !aliens[i].jiggle;

				aliens[i].dessinerExtraTerrestre();
			}
		}
		// pour la deuxieme ligne on les fait bouger jusqu'a la bordure de gauche et puis vice versa
		for (int i = 8; i < _nb_aliens; i++) {

			if (aliens[i].isAlive) {
				aliens[i].effacerExtraTerrestre();

				if (direction_gauche && aliens[i].coord.getPositionX() > 3) {
					aliens[i].coord.setPositionX(aliens[i].coord.getPositionX() - 1);
				}
				else if (!direction_gauche && aliens[i].coord.getPositionX() < nbColonnesTerrain - 3) {
					aliens[i].coord.setPositionX(aliens[i].coord.getPositionX() + 1);
				}
				// aliens[i].jiggle = !aliens[i].jiggle;
			aliens[i].dessinerExtraTerrestre();
			}
		}
			// lorsqu'on arrive a une bordure on change de sens
			if (aliens[8].coord.getPositionX() == 3 || aliens[_nb_aliens-1].coord.getPositionX() == nbColonnesTerrain - 3) {
				direction_gauche = !direction_gauche;
			}

		}

	// on reinitialize le delai
	delaiJiggle.setDelai(1000);
}


//test de collision
void Jeu::testerLaCollision()
{
	for (int i = 0; i < _nb_aliens; i++) {
		for (int j = 0; j < MAX_LASERS; j++) {
			if (sangomar.tabLasers[j].isAlive &&
				// Tester les collisions avec les quatres coins des aliens
					(		sangomar.tabLasers[j].collision(aliens[i].coord.getPositionX(), aliens[i].coord.getPositionY() ) || 
						sangomar.tabLasers[j].collision(aliens[i].coord.getPositionX()+1, aliens[i].coord.getPositionY() ) ||
						sangomar.tabLasers[j].collision(aliens[i].coord.getPositionX() + 2, aliens[i].coord.getPositionY()-1) ||
						sangomar.tabLasers[j].collision(aliens[i].coord.getPositionX() -1, aliens[i].coord.getPositionY()-1)
					)
				) {
				// supprimer l'alien
				aliens[i].supprimerExtraterrestre();
				//incrementation du score
				score += aliens[i].getValeurAllien();
				

			}
		}
	}

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