#ifndef SCENARIO_H
#define SCENARIO_H

#include "Array.h"
class Policier;
class Gangster;
class Heritiere;
class Lieu;


class Scenario {
	Array<Lieu *> listLieu;
	Array<Heritiere *> listHeritiere;
	Array<Policier *> listPolicier;
	Array<Gangster *> listGangster;
	public:
	void scene(void);
	void addHeritiere(std::string _nom, std::string _lieu);
	void addGangster(std::string _nom, std::string _lieu);
	void addPolicier(std::string _nom, std::string _lieu);
	Scenario();
	~Scenario();
};

#endif