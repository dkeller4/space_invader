#include <iostream>
#include "UIKit.h"
#include "ExtraTerrestre.h"

#define LARGUER_FENETRE 150
#define HAUTEUR_FENETRE 70

void AxesXetY() {
	// Axe X (l'axe horizontal)
	for (int i = 0; i < LARGUER_FENETRE; i += 5) {
		UIKit::gotoXY(i, 0);
		cout << i;
	}

	// Axe Y (l'axe vertical)
	for (int i = 0; i < HAUTEUR_FENETRE; i += 5) {
		UIKit::gotoXY(0, i);
		cout << i;
	}
}

int main()
{
	UIKit::setDimensionFenetre(0, 0, LARGUER_FENETRE, HAUTEUR_FENETRE);
	AxesXetY();
	
	UIKit::cadre(5, 5, 140, 15, FOREGROUND_RED);


	ExtraTerrestre::dessinerLigneExtraterrestres(10);


	return 0;
}