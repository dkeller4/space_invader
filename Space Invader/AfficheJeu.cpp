#include "AfficheJeu.h"
#include "UIKit.h"
#include "Menu.h"
#include "Jeu.h"

void jouer() {
	UIKit ecran;

	// Selection du choix du menu
	int choixMenu;

	// Affiche le menu du jeu
	string listeChoix[] = { "Demarrer une partie", "Quitter le jeu" };
	Menu MenuDuJeu("", listeChoix, 2, 8, 30);

	do {
		Jeu spaceInvader;
		// Clear consoles
		system("cls");

		// Cache le curseur
		ecran.curseurVisible(false);

		UIKit::color(FOREGROUND_WHITE + FOREGROUND_INTENSITY);
		choixMenu = MenuDuJeu.afficherMenu();

		if (choixMenu == 1) spaceInvader.startGame();


	} while (choixMenu != 2);

	if (choixMenu == 2)
		exit(0);
}