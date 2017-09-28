#include "test.h"
#include "Scenario.h"
#include "Personnage.h"
#include "Lieu.h"
#include "Transports.h"
#include "value.h"

void testArray(void){
  Array<int> *a = new Array<int>();
  for(int i = 0 ; i < 100 ; i++){
    a->add(i);
  }

  for(int i = 0 ; i < 90 ; i++){
    a->remove(i);
  }

  int i = 0;
  while(a->get(i) != NULL){
    std::cout << *a->get(i)<< "(" << a->getSize() << ")" << " | ";
    a->remove(*a->get(0));
  }
  std::cout << "(" << a->getSize() << ")" << std::endl;
  delete a;
}

void testPersonnage(void){
  std::cout << "Test de la class Personnage :" << std::endl;
  Lieu l("Geneve");
  
  Personnage perso1 = Personnage(&l), perso2 = Personnage("John", &l);
  perso1.parle("coucou");
  perso2.parle("coucou");
  std::cout << "-- Fin de test --" << std::endl;
}

void testLieu(void){
  std::cout << "Test des classes Lieu et Transports :" << std::endl;
  Lieu lieu1, lieu2 = Lieu("quelque part");
  std::cout << "nom 1: " << lieu1.getNom() << std::endl;
  std::cout << "nom 2: " << lieu2.getNom() << std::endl;
  lieu1.getMoyens()[ROUTE].addDesserte(&lieu2);
  std::cout << "Ajout d'un lien ROUTE de \"" << lieu1.getNom() << "\" vers \"" << lieu2.getNom() <<"\""<< std::endl;
  bool test = lieu1.estAccessible(Transports(ROUTE),&lieu2);
  std::cout << "Test de l'existence du lien : " << ((test)?"true":"false") << std::endl;
  if(test)
    std::cout << "\"" << lieu1.getAccessible(ROUTE_STR,0)->getNom() << "\" est relié à \"" << lieu1.getNom() <<"\""<< std::endl;
  else
    std::cout << "Erreur lien non trouve !"<< std::endl;
  lieu2.getMoyens()[AVION].addDesserte(&lieu1);
  std::cout << "Ajout d'un lien AVION de \"" << lieu2.getNom() << "\" vers \"" << lieu1.getNom()<< "\"" << std::endl;
  test = lieu2.estAccessible(Transports(AVION),&lieu1);
  std::cout << "Test de l'existence du lien : " << ((test)?"true":"false") << std::endl;
  if(test)
    std::cout << "\"" << lieu2.getAccessible(AVION_STR,0)->getNom() << "\" est relié à \"" << lieu2.getNom() << "\"" << std::endl;
  else
    std::cout << "Erreur lien non trouve !"<< std::endl;
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

void testDeplacementPersonnage(void){
  
}

void testTP(void){
  Scenario s;
  s.addPolicier("Gabi", "Chicago");
  s.addPolicier("John", "Chicago");
  s.scene();
}