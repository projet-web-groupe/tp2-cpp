#include "Heritiere.h"
#include "Policier.h"

//Array<Heritiere *> Heritiere::listHeritiere;

Heritiere::Heritiere(Lieu * p, std::string n) : Personnage(n,p), captive(false) {
	//listHeritiere.add(this);
}

void Heritiere::setCaptive(bool b){
	captive = b;
}

bool Heritiere::getCaptive(void){
	return captive;
}

void Heritiere::estEnlevee(void){
	captive = true;
	std::cout << "À l'aide ! Je suis "<< nom << " on m'enlève ! Sauvez-moi !" << std::endl;
}
void Heritiere::estLiberee(Policier& c){
	captive = false;
std::cout << "Grand merci, "<< c.getNom() << ", vous m'avez sauvée !" << std::endl;	
}