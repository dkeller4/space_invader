#pragma once
#include "Martien.h"

class miniMartien : public Martien {
private:
public: 

	// constructeurs
	miniMartien();

	// methodes

	// setter miniMartien
	void setMiniMartien(int x, int y, int type);


	void dessinerExtraTerrestre();

	void effacerExtraTerrestre();

	void supprimerExtraterrestre();
	int getValeurAllien() const;
};