#include "Personnage.h"

Personnage::Personnage() : nom("noName")
{
  std::cout << "Bonjour, je suis " <<nom << std::endl;
}

Personnage::Personnage(std::string n) : nom(n)
{
  std::cout << "Bonjour, je suis " << nom << std::endl;
}

Personnage::~Personnage()
{
  std::cout << "Il n'y a plus rien à faire ici pour moi, " << nom  << ". Adieu"<< std::endl;
}

void Personnage::parle(std::string text){
  std::cout << nom << " : " << text << std::endl;
}
