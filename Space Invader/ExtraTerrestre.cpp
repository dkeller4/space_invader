#include "ExtraTerrestre.h"
#include <stdlib.h>
#include <iostream>
#include "UIKit.h"
using namespace std;

int ExtraTerrestre::nombreExtraTerrestre = 0;


ExtraTerrestre::ExtraTerrestre(int type,int valeur)
{
	typeExtraTerrestre=type;
	valeurExtraTerrestre=valeur;
}


void ExtraTerrestre::reduireNombreExtraTerrestre()
{
	nombreExtraTerrestre--;
}

int ExtraTerrestre::getNombreExtraTerrestre()
{
	return nombreExtraTerrestre;
}

void ExtraTerrestre::resetNombreExtraTerrestre()
{
	nombreExtraTerrestre=0;
}

void ExtraTerrestre::removeExtraTerrestre() const
{
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << " ";	
}

void ExtraTerrestre::putExtraTerrestre() const
{
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << char(typeExtraTerrestre);
}

int ExtraTerrestre::ajouterPoints() const
{
	return valeurExtraTerrestre;
}

void ExtraTerrestre::resetExtraTerrestre()
{
	coord.setPositionX(rand()%40+1);
	coord.setPositionY(rand()%20+1);
	isAlive = true;
	nombreExtraTerrestre++;
}

ExtraTerrestre::ExtraTerrestre()
{
	typeExtraTerrestre = 0;
	valeurExtraTerrestre = 0;
}

void ExtraTerrestre::dessinerExtraTerrestre(int x, int y)
{
	// on place la position de l'extraterrestre dans son attribut de classe Coord
	coord.setPositionX(x);
	coord.setPositionY(y);

	if (typeExtraTerrestre == 0) UIKit::color(FOREGROUND_RED);
	else if (typeExtraTerrestre == 1) UIKit::color(FOREGROUND_BLUE);

	// on dessine la premiere ligne 
	UIKit::gotoXY(x+1, y+1);
	cout << (char)47;
	cout << (char)92;

	// on dessine la deuxieme ligne 
	UIKit::gotoXY(x, y);
	cout << (char)40;
	cout << (char)16;
	cout << (char)17;
	cout << (char)41;
}

void ExtraTerrestre::dessinerLigneExtraterrestres(int nombre_extraterrestres)
{
	ExtraTerrestre * monstres = new ExtraTerrestre[nombre_extraterrestres];
	for (int i = 0; i < nombre_extraterrestres; i++) {
		if (i % 2 == 1) monstres[i].typeExtraTerrestre = 1;
		monstres[i].dessinerExtraTerrestre(30 + 90/nombre_extraterrestres * i, 25);
	}
}

