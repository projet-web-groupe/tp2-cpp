#include "test.h"

int main(){
  //testPersonnage();
  //testLieu();
  testTransports();
  return 0;
}

void testPersonnage(void){
  std::cout << "Test de la class Personnage :" << std::endl;
  Lieu l;
  
  Personnage perso1 = Personnage(&l), perso2 = Personnage("John", &l);
  perso1.parle("coucou");
  perso2.parle("coucou");
  std::cout << "-- Fin de test --" << std::endl;
}

void testLieu(){
  std::cout << "Test de la class Lieu :" << std::endl;
  Lieu lieu1, lieu2 = Lieu("quelque part");
  std::cout << "nom 1: " << lieu1.getNom() << std::endl;
  std::cout << "nom 2: " << lieu2.getNom() << std::endl;
  std::cout << "-- Fin de test --" << std::endl;
}

void testTransports(void){
  std::cout << "Test de la class Lieu :" << std::endl;
  Transports t;
  std::cout << "mode : ";
  //affichage / recup string du mode
  std::cout << std::endl;
  std::cout << "-- Fin de test --" << std::endl;
}
