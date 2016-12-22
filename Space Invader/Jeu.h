#pragma once

#include "MonVaisseau.h"
#include "Menu.h"
#include "UIKit.h"
#include "ExtraTerrestre.h"
#include "miniMartien.h"


#define FOREGROUND_CYAN 0x0003
#define FOREGROUND_YELLOW 0x0006
#define FOREGROUND_WHITE 0x0007
#define MAX_ALIENS 25

class Jeu
{
private:

	static const int nbLignesTerrain = 50 + 1;
	static const int nbColonnesTerrain = 70;
	int score;
	bool gameOver;
	bool MortVaisseau;
	bool MortMiniMartienJaune;
	bool MortMiniMartienRouge;
	Timer delaiJiggle;
	Timer delaiTir;
	MonVaisseau sangomar;
	miniMartien aliens[MAX_ALIENS];
	bool direction_gauche = true;
	int _nb_aliens = 0;
	UIKit ecran;
	void debut();

public:
	Jeu();
	void demarrerLeJeu();
	void mouvement();
	void testerLaCollision();
	void affichageDuTerrain() const;
	void GameOver();
	void reinitialiserLejeu();
	void Victoire();
	void affichageScore();
	void ligneExtraTerrestres(int, int, int);
};

