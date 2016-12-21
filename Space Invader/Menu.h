//la classe menu

#ifndef __MENU_H
#define __MENU_H

#include <iostream>
using namespace std;
#include <string>
#include <windows.h>	
#include <conio.h>	
#include <ctype.h>	


class Menu
{
	string _titre;
	int _nbItem;
	string* _listeChoix;
	COORD coinHG;
	//gestion interne
	COORD _posActu;
	COORD _posLast;
	COORD _posFirst;
	int choix;

protected:
	void deplacer(COORD origine, COORD cible);
	int getTailleMax();
	void gotoXY(COORD pos);
	void init();

public:
	Menu(string titre, string* listeChoix, int nbItem, int ligneDebut, int coloneDebut);
	~Menu();
	int afficherMenu();
	void gotoXY(int c, int l);
};

#endif