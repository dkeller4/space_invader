#ifndef EXTRATERRESTRE_H
#define EXTRATERRESTRE_H

#include "Coord.h"

enum typeExtraTerrestre {
	rouge, bleu
};

class ExtraTerrestre
{
protected:
	static int nombreExtraTerrestre;
	int typeExtraTerrestre;
	int valeurExtraTerrestre;

public:
	Coord coord;
	bool isAlive;

	ExtraTerrestre(int, int);
	static void reduireNombreExtraTerrestre();
	static int getNombreExtraTerrestre();
	static void resetNombreExtraTerrestre();
	void removeExtraTerrestre() const;
	void putExtraTerrestre() const;
	int ajouterPoints() const;
	void resetExtraTerrestre();
	ExtraTerrestre();
	void dessinerExtraTerrestre(int x, int y);
	static void dessinerLigneExtraterrestres(const int nombre_extraterrestres);
};

#endif




