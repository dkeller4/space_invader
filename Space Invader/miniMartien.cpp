#include "miniMartien.h"
#include "UIKit.h"


miniMartien::miniMartien() :Martien(0, 0)
{
	this->coord.setPositionX(0);
	this->coord.setPositionY(0);
	this->jiggle = true;
}

void miniMartien::setMiniMartien(int x, int y, int type) 
{
	// on place la position de l'extraterrestre dans son attribut de classe Coord
	this->coord.setPositionX(x);
	this->coord.setPositionY(y);

	this->typeExtraTerrestre = type;
	
}

void miniMartien::dessinerExtraTerrestre()
{
	if (this->typeExtraTerrestre == 1)	UIKit::color(FOREGROUND_RED + FOREGROUND_INTENSITY);
	else if (this->typeExtraTerrestre == 2)	UIKit::color(FOREGROUND_BLUE + FOREGROUND_INTENSITY);
	else if (this->typeExtraTerrestre == 3)	UIKit::color(FOREGROUND_GREEN + FOREGROUND_INTENSITY);


	// on dessine la premiere ligne 
	UIKit::gotoXY(this->coord.getPositionX(), this->coord.getPositionY());
	if (this->jiggle) {
		cout << (char)47;
		cout << (char)92;
	}
	else {
		cout << (char)92;
		cout << (char)47;
	}

	// on dessine la deuxieme ligne 
	UIKit::gotoXY(this->coord.getPositionX() -1, this->coord.getPositionY()-1);
	cout << (char)40;
	cout << (char)16;
	cout << (char)17;
	cout << (char)41;

}

//Pour avoir le score pour chaque type de martien
int miniMartien::getValeurAllien() const {
	int valeur;
	if (this->typeExtraTerrestre == 1)
		valeur = 5;

	else if (this->typeExtraTerrestre == 2)
		valeur = 10;
	else
		valeur = 15;
	return valeur;
}

void miniMartien::effacerExtraTerrestre() {
	// On supprime la première ligne
	UIKit::gotoXY(this->coord.getPositionX(), this->coord.getPositionY());
	cout << "  ";

	// on supprime la deuxieme ligne 
	UIKit::gotoXY(this->coord.getPositionX() - 1, this->coord.getPositionY() - 1);
	cout << "    ";
}

void miniMartien::supprimerExtraterrestre()
{
	this->effacerExtraTerrestre();

	this->isAlive = false;

	this->coord.setPositionX(100);
	this->coord.setPositionY(100);

}

