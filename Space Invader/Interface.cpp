#include "Interface.h"
#include "UIKit.h"
#include "Menu.h"
#include "Jeu.h"
#include <iostream>

using namespace std;

void play() {
	UIKit ecran;

	// choix d'une action du menu
	int choix;

	// Affichage du menu du jeu
	string listeChoix[] = { "Demarrer une partie","Aide", "Quitter le jeu" };
	Menu Menu("(^SANGOMAR^) contre les <MINIMARTIENS>      ", listeChoix, 3, 8, 30);

	do {
		Jeu space;
		// Clear consoles
		system("cls");

		// Cache le curseur
		ecran.curseurVisible(false);

		UIKit::color(FOREGROUND_RED + FOREGROUND_INTENSITY);
		choix = Menu.afficherMenu();

		if (choix == 1) space.demarrerLeJeu();
		if (choix == 2) {
			                system("cls");
			                cout << "Si tu es un inconditionnel des jeux flash dans lesquels"
				            << "tu te retrouves au centre des combats, alors Space Invaders"
				            << "Click, ce jeu flash � venir est fait pour toi. Space Invaders"
				            << "Click est un jeu  flash class� dans la cat�gorie des jeux des combats."
				            << "D�couvre ce jeu et plein d�autres jeux flash du genre ou de cat�gories "
				            << "diff�rents si tu visites notre site web de jeux flash gratuits en ligne." << endl;
							Sleep(1000);
							cin.ignore(512, '\n');
			               if (_kbhit()) {			
				                           char touche = _getch();		
                                            if (touche)
												Menu.afficherMenu();
				                          }

			             }
		

	} while (choix != 3);

		exit(0);
}