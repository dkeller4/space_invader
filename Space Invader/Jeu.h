#pragma once

#include "MonVaissau.h"
#include "Menu.h"
#include "UIKit.h"
#include "ExtraTerrestre.h"

#define FOREGROUND_MAGENTA 0x0005
#define FOREGROUND_CYAN 0x0003
#define FOREGROUND_YELLOW 0x0006
#define FOREGROUND_WHITE 0x0007

static const string fichierTitre("titreJeu.txt");
static const string fichierGameOver("gameOver.txt");
static const string fichierVictoire("victoire.txt");

class Jeu
{
private:

	//les attributs
	static const int nbLignesTerrain = 40 + 1;
	static const int nbColonnesTerrain = 60;
	int score;
	bool finDeJeu;
	bool vaissauEstMort;
	bool unVenusienEstMort;
	bool unSaturnienEstMort;
	MonVaissau sangomar;
	UIKit ecran;

	//les méthodes privées
	void lireFichier(const string & monfichier);
	void SauveDansFichier(const string & monfichier);
	void debut();

public:

	//constructeur
	Jeu();

	//méthodes spécifiques
	void startGame();
	void resetGame();
	void testCollision();
	void apparitionExraTerrestres();
	void afficherTerrain() const;
	void afficherTitreJeu();
	void afficherGameOver();
	void afficherVictoire();
	void afficherScore();
};