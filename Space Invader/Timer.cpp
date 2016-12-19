#include "Timer.h"

#include <time.h>

//	constructeur
Timer::Timer() {
	delai = 100;
	date = clock();
}

Timer::Timer(int delai) {
	this->delai = delai;
	this->date = clock();
}

void Timer::setDelai(int delai) {
	this->delai = delai;
}

//	méthode spécifique
bool Timer::tempsEcoule() {
	bool retour = false;

	if (clock() >= date + delai) {
		date = clock();
		retour = true;
	}

	return retour;
}