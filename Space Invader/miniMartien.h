#pragma once
#include "Martien.h"

class miniMartien : public Martien {
public: 

	miniMartien();

	void dessinerExtraTerrestre(int x, int y);
	miniMartien* dessinerLigneExtraterrestres(int nombre_extraterrestres, int y);
};