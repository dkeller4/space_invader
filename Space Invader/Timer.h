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

	//	m�thode sp�cifique
	void setDelai(int delai);
	bool tempsEcoule();
};