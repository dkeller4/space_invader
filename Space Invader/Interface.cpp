#include "Interface.h"
#include "UIKit.h"
#include "Menu.h"
#include "Jeu.h"


void play() {
	UIKit ecran;

	// Selection du choix du menu
	int choix;

	// Affiche le menu du jeu
	string listeChoix[] = { "Demarrer une partie", "Quitter le jeu"};
	Menu MenuDuJeu("", listeChoix, 2, 8, 30);

	do {
		Jeu spaceInvader;
		// Clear consoles
		system("cls");

		// Cache le curseur
		ecran.curseurVisible(false);

		UIKit::color(FOREGROUND_CYAN + FOREGROUND_INTENSITY);
		choix = MenuDuJeu.afficherMenu();

		if (choix == 1) spaceInvader.demarrerLeJeu();


	} while (choix != 2);

	if (choix == 2)
		exit(0);
}