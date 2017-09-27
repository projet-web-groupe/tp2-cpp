#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include "Lieu.h"
class Transports;
//class Lieu;

class Personnage {
protected:
	std::string nom;
	Lieu * pos;
	int randInt(int min, int max);
	double randDouble(double min, double max);
public:
	Personnage(Lieu * p);
	Personnage(std::string n, Lieu * p);
	virtual ~Personnage();
	void parle(std::string text);
	void deplace(Lieu * l);
	void deplace(Lieu * l, Transports t);
	void setPos(Lieu * l);
	Lieu * getPos(void);
	std::string getNom(void);
	void deplaceAleatoire(void);
	virtual void action();
};

#endif
