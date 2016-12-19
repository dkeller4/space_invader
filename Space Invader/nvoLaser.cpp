#include <iostream>
#include "nvoLaser.h"
#include "Coord.h"
#include <string>
#include "UIKit.h"

using namespace std;

//constructeur avec parametre
nvoLaser::nvoLaser(int direction){
	this->direction = direction;
}

//constructeur sans parametre
nvoLaser::nvoLaser(){}

//initialiser laser
void nvoLaser::enclencherLaser(int x, int y, int direction){
	coord.setPositionX(x);
	coord.setPositionY(y + direction);
	putLaser();
	isAlive = true;
}

//deplacer laser
void nvoLaser::bougeLaser(int direction){
	this->direction = direction;
	removeLaser();
	if (coord.getPositionY() < 40 && coord.getPositionY() > 1)
	{
		coord.setPositionY(coord.getPositionY() + direction);
		putLaser();
	}
	else
		isAlive = false;
}

//mettre le laser
void nvoLaser::putLaser() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	if (direction == 1) {
		UIKit::color(FOREGROUND_GREEN + FOREGROUND_INTENSITY);
		cout << '|';
	}
	else {
		UIKit::color(FOREGROUND_RED + FOREGROUND_INTENSITY);
		cout << '|';
	}

}

//test de collision
bool nvoLaser::collision(int posX, int posY)
{
	bool collision = false;
	if (coord.getPositionX() == posX && coord.getPositionY() == posY){
		killLaser();
		collision = true;
	}
	return collision;
}