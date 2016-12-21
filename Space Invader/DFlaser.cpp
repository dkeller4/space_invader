#include <iostream>
#include "DFLaser.h"
#include "Coord.h"
#include <string>
#include "UIKit.h"

using namespace std;

#define FOREGROUND_WHITE 0x0007

//constructeur avec parametre
DFLaser::DFLaser(int direction){
	this->direction = direction;
}

//constructeur sans parametre
DFLaser::DFLaser(){}

//initialiser laser
void DFLaser::initLaser(int x, int y, int direction){
	coord.setPositionX(x);
	coord.setPositionY(y + direction);
	putLaser();
	isAlive = true;
}

//deplacer laser
void DFLaser::moveLaser(int direction){
	this->direction = direction;
	removeLaser();
	if (coord.getPositionY() < 50 && coord.getPositionY() > 1)
	{
		coord.setPositionY(coord.getPositionY() + direction);
		putLaser();
	}
	else
		isAlive = false;
}

//mettre le laser
void DFLaser::putLaser() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	if (direction == 1) {
		UIKit::color(FOREGROUND_GREEN + FOREGROUND_INTENSITY);
		cout << '|';
	}
	else {
		UIKit::color(FOREGROUND_WHITE + FOREGROUND_INTENSITY);
		cout << '|';
	}
}

//test de collision
bool DFLaser::collision(int posX, int posY)
{
	bool collision = false;
	if (coord.getPositionX() == posX && coord.getPositionY() == posY){
		killLaser();
		collision = true;
	}
	return collision;
}