#pragma once
#include "Martien.h"

class miniMartien : public Martien {
public: 

	// constructeurs
	miniMartien();

	// methodes

	// setter miniMartien
	void setMiniMartien(int x, int y, int type);


	void dessinerExtraTerrestre();
	//miniMartien* dessinerLigneExtraterrestres(int nombre_extraterrestres, int y);
};