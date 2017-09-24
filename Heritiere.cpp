#include "Heritiere.h"

Heritiere::Heritiere(Lieu * p, std::string n) : pos(p), nom(n), captive(false) {
  std::cout << "Bonjour, je suis " << nom << std::endl;
}

void Heritiere::setCaptive(bool b){
  captive = b;
}
