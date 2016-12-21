#pragma once

#include "MonVaisseau.h"
#include "Menu.h"
#include "UIKit.h"
#include "ExtraTerrestre.h"
#include "miniMartien.h"

#define FOREGROUND_MAGENTA 0x0005
#define FOREGROUND_CYAN 0x0003
#define FOREGROUND_YELLOW 0x0006
#define FOREGROUND_WHITE 0x0007


class Jeu
{
private:

	static const int nbLignesTerrain = 60 + 1;
	static const int nbColonnesTerrain = 70;
	int score;
	bool gameOver;
	bool MortVaisseau;
	bool MortMiniMartienJaune;
	bool MortMiniMartienRouge;
	MonVaisseau sangomar;
	UIKit ecran;
	void debut();

public:
	Jeu();
	void demarrerLeJeu();
	miniMartien* apparitionExraTerrestres(int y);
	void testerLaCollision();
	void affichageDuTerrain() const;
	void GameOver();
	void reinitialiserLejeu();
	void Victoire();
	void affichageScore();
};