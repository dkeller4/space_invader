//implementation de la clase menu
#include "Menu.h"
#include "UIKit.h"

Menu::Menu(string titre, string* listeChoix, int nbItem, int ligneDebut, int colonneDebut)
{
	this->_titre = titre;
	this->_listeChoix = new string[nbItem];
	for (int i = 0; i<nbItem; i++)
	{
		this->_listeChoix[i] = listeChoix[i];
	}
	this->_nbItem = nbItem;
	this->coinHG.X = colonneDebut;
	this->coinHG.Y = ligneDebut;

	//initialiser les positions
	init();
}

void Menu::init()
{
	//initialisation des position et choix
	this->choix = 1;
	this->_posActu.X = coinHG.X;
	this->_posActu.Y = coinHG.Y + 2;
	this->_posFirst = _posActu;
	this->_posLast = _posFirst;
	this->_posLast.Y = _posFirst.Y + 2 * (_nbItem - 1);
}

Menu::~Menu()
{
	delete[]this->_listeChoix;
}

int Menu::afficherMenu()
{
	//setter les positions

	COORD posNext = _posActu;
	//dessiner le menu
	gotoXY(coinHG);
	cout << _titre << endl;
	for (int i = 0; i<_nbItem; i++)
	{
		gotoXY(coinHG.X + 4, _posFirst.Y + (2 * i));
		cout << _listeChoix[i] << endl;
	}

	//capter les flèches
	int touche;

	//deplacer(_posActu, _posFirst);
	deplacer(_posActu, _posActu);
	do
	{
		posNext = _posActu;
		touche = _getch();
		if (touche == 224)
		{
			touche = _getch();
		}
		//déplacer
		switch (touche){
		case 80:	//touche bas
			if (_posActu.Y == _posLast.Y) //si on est déjà en bas
			{
				deplacer(_posActu, _posFirst);
				_posActu = _posFirst;
				choix = 1;
			}
			else
			{
				posNext.Y += 2;
				deplacer(_posActu, posNext);
				_posActu.Y += 2;
				choix++;
			}
			break;
		case 72:	//touche haut
			if (_posActu.Y == _posFirst.Y) //si on est déjà en haut
			{
				deplacer(_posActu, _posLast);
				_posActu = _posLast;
				choix = _nbItem;
			}
			else
			{
				posNext.Y -= 2;
				deplacer(_posActu, posNext);
				_posActu.Y -= 2;
				choix--;
			}
			break;
		}

	} while (touche != 13);
	//retourner le choix

	return choix;
}


void Menu::deplacer(COORD origine, COORD cible){
	//effacer
	gotoXY(origine);
	cout << "   " << endl;
	//dessiner
	gotoXY(cible);
	cout << ":->" << endl;
}


int Menu::getTailleMax(){
	return 0;
}


void Menu::gotoXY(COORD pos){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void Menu::gotoXY(int c, int l){
	COORD coord;
	coord.X = c;
	coord.Y = l;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}