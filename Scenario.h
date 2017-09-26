#ifndef SCENARIO_H
#define SCENARIO_H

#include "Array.h"
class Personnage;
class Policier;
class Gangster;
class Heritiere;
class Lieu;


class Scenario {
	Array<Lieu *> listLieu;
	Array<Personnage *> listPerso;
	public:
	void scene(void);
	void addPerso(Personnage *p);
	Scenario();

};

#endif