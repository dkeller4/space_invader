#include "Interface.h"
#include "UIKit.h"
#include "Menu.h"
#include "Jeu.h"


void play() {
	UIKit ecran;

	// Selection du choix du menu
	int choix;

	// Affiche le menu du jeu
	string listeChoix[] = { "Demarrer une partie","Aide", "Quitter le jeu" };
	Menu Menu("CHOISISSEZ UNE ACTION.....(^_^)", listeChoix, 3, 8, 30);

	do {
		Jeu space;
		// Clear consoles
		system("cls");

		// Cache le curseur
		ecran.curseurVisible(false);

		UIKit::color(FOREGROUND_CYAN + FOREGROUND_INTENSITY);
		choix = Menu.afficherMenu();

		if (choix == 1) space.demarrerLeJeu();
		if (choix == 2) {
			                system("cls");
			                cout << "Si tu es un inconditionnel des jeux flash dans lesquels"
				            << "tu te retrouves au centre des combats, alors Space Invaders"
				            << "Click, ce jeu flash à venir est fait pour toi. Space Invaders"
				            << "Click est un jeu  flash classé dans la catégorie des jeux des combats."
				            << "Découvre ce jeu et plein d’autres jeux flash du genre ou de catégories "
				            << "différents si tu visites notre site web de jeux flash gratuits en ligne." << endl;

			               if (_kbhit()) {			
				                           char touche = _getch();		
                                            if (touche)
												Menu.afficherMenu();
				                          }

			             }
		

	} while (choix != 3);

		exit(0);
}