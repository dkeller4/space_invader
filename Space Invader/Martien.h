#ifndef MARTIEN_H
#define MARTIEN_H

#include "ExtraTerrestre.h"

class Martien : public ExtraTerrestre // C"est quoi??
{
	bool jiggle;

public:
	Martien(int,int);
	void jiggleMartien();
};

#endif
