#include "miniMartien.h"
#include "UIKit.h"

miniMartien::miniMartien() :Martien(0,0)
{
	typeExtraTerrestre = 0;
	valeurExtraTerrestre = 0;
}

void miniMartien::dessinerExtraTerrestre(int x, int y)
{
	if (this->typeExtraTerrestre == 1)	UIKit::color(FOREGROUND_RED);
	else if (this->typeExtraTerrestre == 2)	UIKit::color(FOREGROUND_BLUE);
	else if (this->typeExtraTerrestre == 3)	UIKit::color(FOREGROUND_GREEN);

	// on place la position de l'extraterrestre dans son attribut de classe Coord
	coord.setPositionX(x);
	coord.setPositionY(y);

	if (typeExtraTerrestre == 0) UIKit::color(FOREGROUND_RED);
	else if (typeExtraTerrestre == 1) UIKit::color(FOREGROUND_BLUE);

	// on dessine la premiere ligne 
	UIKit::gotoXY(x + 1, y + 1);
	cout << (char)47;
	cout << (char)92;

	// on dessine la deuxieme ligne 
	UIKit::gotoXY(x, y);
	cout << (char)40;
	cout << (char)16;
	cout << (char)17;
	cout << (char)41;

}

miniMartien* miniMartien::dessinerLigneExtraterrestres(int nombre_miniMartiens, int y)
{
	miniMartien * monstres = new miniMartien[nombre_miniMartiens];
	for (int i = 0; i < nombre_miniMartiens; i++) {
		if (i % 2 == 1) monstres[i].typeExtraTerrestre = 1;
		monstres[i].dessinerExtraTerrestre( 2+ 60 / nombre_miniMartiens * i, y);
	};
	return monstres;
}
