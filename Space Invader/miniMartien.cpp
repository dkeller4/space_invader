#include "miniMartien.h"
#include "UIKit.h"


miniMartien::miniMartien() :Martien(0, 0)
{
	this->coord.setPositionX(0);
	this->coord.setPositionY(0);
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
	cout << (char)47;
	cout << (char)92;

	// on dessine la deuxieme ligne 
	UIKit::gotoXY(this->coord.getPositionX() -1, this->coord.getPositionY()-1);
	cout << (char)40;
	cout << (char)16;
	cout << (char)17;
	cout << (char)41;

}


void miniMartien::supprimerExtraterrestre()
{
	// On supprime la premi�re ligne
	UIKit::gotoXY(this->coord.getPositionX(), this->coord.getPositionY());
	cout << "  ";

	// on supprime la deuxieme ligne 
	UIKit::gotoXY(this->coord.getPositionX() - 1, this->coord.getPositionY() - 1);
	cout << "    ";
}


