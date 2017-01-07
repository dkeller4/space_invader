#include "Jeu.h"
#include "UIKit.h"
#include "Timer.h"
#include <time.h>
#include <string>
#include <iostream>
#include "ExtraTerrestre.h"
#include "miniMartien.h"
#include "Interface.h"
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
	ecran.gotoXY(nbColonnesTerrain + 1 + 12, 24);
	cout << score;

	ecran.color(FOREGROUND_CYAN + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 10, 26);
	cout << "Vies:";


	ecran.color(FOREGROUND_YELLOW + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 12, 28);
	cout << sangomar.vies;

	ecran.color(FOREGROUND_CYAN + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 10, 30);
	cout << "Aliens:";


	ecran.color(FOREGROUND_YELLOW + FOREGROUND_INTENSITY);
	ecran.gotoXY(nbColonnesTerrain + 1 + 12, 32);
	cout << compteur_aliens;
}

void Jeu::demarrerLeJeu() {

	gameOver = false;
	affichageDuTerrain();
	// chargement du son
	PlaySound(TEXT("laser.mid"), NULL, SND_MEMORY);

	// pour faire apparaitre le vaisseau
	sangomar.modifierPosition(75);
	 
	// creation du vaisseau aliens
	vaisseau_aliens.setvaisseauAlien();

	// pour faire apparaitre les miniMartiens
	ligneExtraTerrestres(10, 8, 3);
	ligneExtraTerrestres(15, 5, 5);
	ligneExtraTerrestres(20, 6, 6);
	
	

	
	do {
		//	le vaisseau tire
		sangomar.tirerLaser();

		// tirs des aliens
		vaisseau_aliens.gestionLaserAliens(25, _nb_aliens, aliens);

		// tester les tirs du vaisseau
		testerLaCollision();

		// tester les tirs des aliens
		testerCollisionsAliens();

		// mouvement des aliens
		mouvement();

		// mise a jour du nombre de vies
		ecran.color(FOREGROUND_YELLOW + FOREGROUND_INTENSITY);
		ecran.gotoXY(nbColonnesTerrain + 1 + 12, 28);
		cout << sangomar.vies;

		// mise a jour du nombre d'aliens (effacer puis reecriture)
			if (compteur_aliens == 9) {
				ecran.gotoXY(nbColonnesTerrain + 1 + 12, 32);
				cout << "  ";
			}
			ecran.gotoXY(nbColonnesTerrain + 1 + 12, 32);
			cout << compteur_aliens;

		if (sangomar.vies == 0) MortVaisseau = true;

		if (compteur_aliens == 0) gameOver = true; 

		if (MortVaisseau)
			gameOver = true;

	} while (!gameOver);

	if (MortVaisseau)
		GameOver();
	else Victoire();

}


// mouvement des aliens
void Jeu::mouvement() {

	if (delaiJiggle.tempsEcoule()) {

		// premiere ligne -> mouvement droite-gauche
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
		// deuxieme ligne -> bouger jusqu'a la bordure de gauche et puis vice versa
		for (int i = 8; i < 13; i++) {

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
			// troisieme ligne -> mouvement droite-gauche
			if (aliens[8].coord.getPositionX() == 3 || aliens[12].coord.getPositionX() == nbColonnesTerrain - 3) {
				direction_gauche = !direction_gauche;
			}

			for (int i = 13; i < _nb_aliens; i++) {

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
		}

	// on reinitialise le delai
	delaiJiggle.setDelai(1000);
}


//tester les tirs du vaisseau
void Jeu::testerLaCollision()
{
	for (int i = 0; i < _nb_aliens; i++) {
		for (int j = 0; j < MAX_LASERS; j++) {
			if (sangomar.tabLasers[j].isAlive&& 
				// Tester les collisions avec les quatres coins des aliens
					(		sangomar.tabLasers[j].collision(aliens[i].coord.getPositionX(), aliens[i].coord.getPositionY() ) || 
						sangomar.tabLasers[j].collision(aliens[i].coord.getPositionX()+1, aliens[i].coord.getPositionY() ) ||
						sangomar.tabLasers[j].collision(aliens[i].coord.getPositionX() + 2, aliens[i].coord.getPositionY()-1) ||
						sangomar.tabLasers[j].collision(aliens[i].coord.getPositionX() -1, aliens[i].coord.getPositionY()-1)
					)
				) {
				// supprimer l'alien
				aliens[i].supprimerExtraterrestre(); 
				compteur_aliens = compteur_aliens- 1;
			}
		}
	}
}

// tester les tirs des aliens
void Jeu::testerCollisionsAliens() {

	if (delaiVaisseauVies.tempsEcoule()){

		for (int j = 0; j < MAX_LASERS; j++) {
			if (sangomar.collision(vaisseau_aliens.tabLasers[j].coord.getPositionX(), vaisseau_aliens.tabLasers[j].coord.getPositionY())) {
				sangomar.vies -= 1;
				sangomar.putVaisseau(true);
			}
		}
	}
	delaiVaisseauVies.setDelai(100);
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
		Sleep(40);
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
		Sleep(40);
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