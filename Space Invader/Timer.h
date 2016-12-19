#pragma once

class Timer {
private:
	//	attributs
	int delai;
	int date;

public:
	//	constructeur
	Timer();
	Timer(int delai);

	//	méthode spécifique
	void setDelai(int delai);
	bool tempsEcoule();
};