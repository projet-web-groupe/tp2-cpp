#include "Ganster.h"

Ganster::Ganster(Lieu * p,std::string n,std::string g) :pos(p),nom(n), gang(g), recompense(100), enPrison(false), butin(0){
  std::cout << "Je suis " << nom << ", membre du gang " << g << ".\n";
}
