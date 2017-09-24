#include "test.h"

int main(){
  //testPersonnage();
  //testLieu();
  //testTransports();
  testTP();
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

void testTP(void){
  /*
    route -> rouge
    bateau -> bleu
    train -> vert
    avion -> violet
   */
  Lieu edimbourg("Edimbourg"),
    londres("Londres"),
    brest("Brest"),
    quimper("Quimper"),
    rennes("Rennes"),
    nantes("Nantes"),
    bordeaux("Bordeaux"),
    paris("Paris"),
    marseille("Marseille"),
    calais("Calais"),
    douvres("Douvres"),
    rome("Rome"),
    lyon("Lyon"),
    strasbourg("Strabourg"),
    bruxelles("Bruxelles"),
    cologne("Cologne"),
    francfort("Francfort"),
    munich("Munich"),
    geneve("Geneve"),
    milan("Milan"),
    florence("Florence");

  Personnage p("John",&paris);
  //Construction des lien entre les villes
  edimbourg.getMoyens()[TRAIN].addDesserte(&londres);

  londres.getMoyens()[TRAIN].addDesserte(&edimbourg);
  londres.getMoyens()[AVION].addDesserte(&paris);
  londres.getMoyens()[AVION].addDesserte(&francfort);
  londres.getMoyens()[ROUTE].addDesserte(&douvres);

  brest.getMoyens()[TRAIN].addDesserte(&rennes);
  brest.getMoyens()[BATEAU].addDesserte(&nantes);
  brest.getMoyens()[BATEAU].addDesserte(&bordeaux);

  quimper.getMoyens()[TRAIN].addDesserte(&rennes);
  quimper.getMoyens()[TRAIN].addDesserte(&nantes);

  rennes.getMoyens()[TRAIN].addDesserte(&brest);
  rennes.getMoyens()[TRAIN].addDesserte(&quimper);
  rennes.getMoyens()[TRAIN].addDesserte(&paris);
  rennes.getMoyens()[ROUTE].addDesserte(&paris);
  rennes.getMoyens()[ROUTE].addDesserte(&nantes);

  nantes.getMoyens()[TRAIN].addDesserte(&quimper);
  nantes.getMoyens()[TRAIN].addDesserte(&paris);
  nantes.getMoyens()[TRAIN].addDesserte(&bordeaux);
  nantes.getMoyens()[ROUTE].addDesserte(&rennes);
  nantes.getMoyens()[BATEAU].addDesserte(&brest);

  bordeaux.getMoyens()[TRAIN].addDesserte(&nantes);
  bordeaux.getMoyens()[TRAIN].addDesserte(&paris);
  bordeaux.getMoyens()[BATEAU].addDesserte(&brest);

  paris.getMoyens()[TRAIN].addDesserte(&rennes);
  paris.getMoyens()[TRAIN].addDesserte(&nantes);
  paris.getMoyens()[TRAIN].addDesserte(&bordeaux);
  paris.getMoyens()[TRAIN].addDesserte(&bruxelles);
  paris.getMoyens()[TRAIN].addDesserte(&strasbourg);
  paris.getMoyens()[TRAIN].addDesserte(&lyon);
  paris.getMoyens()[ROUTE].addDesserte(&calais);
  paris.getMoyens()[ROUTE].addDesserte(&rennes);
  paris.getMoyens()[AVION].addDesserte(&londres);
  paris.getMoyens()[AVION].addDesserte(&marseille);

  marseille.getMoyens()[AVION].addDesserte(&paris);
  marseille.getMoyens()[TRAIN].addDesserte(&lyon);
  marseille.getMoyens()[BATEAU].addDesserte(&rome);

  calais.getMoyens()[ROUTE].addDesserte(&paris);
  calais.getMoyens()[ROUTE].addDesserte(&bruxelles);
  calais.getMoyens()[BATEAU].addDesserte(&douvres);

  douvres.getMoyens()[ROUTE].addDesserte(&londres);
  douvres.getMoyens()[BATEAU].addDesserte(&calais);

  rome.getMoyens()[ROUTE].addDesserte(&florence);
  rome.getMoyens()[BATEAU].addDesserte(&marseille);

  lyon.getMoyens()[TRAIN].addDesserte(&paris);
  lyon.getMoyens()[TRAIN].addDesserte(&geneve);
  lyon.getMoyens()[TRAIN].addDesserte(&marseille);
  lyon.getMoyens()[TRAIN].addDesserte(&milan);

  strasbourg.getMoyens()[TRAIN].addDesserte(&paris);
  strasbourg.getMoyens()[TRAIN].addDesserte(&munich);

  bruxelles.getMoyens()[TRAIN].addDesserte(&paris);
  bruxelles.getMoyens()[TRAIN].addDesserte(&cologne);
  bruxelles.getMoyens()[ROUTE].addDesserte(&calais);

  cologne.getMoyens()[TRAIN].addDesserte(&bruxelles);
  cologne.getMoyens()[ROUTE].addDesserte(&francfort);

  francfort.getMoyens()[ROUTE].addDesserte(&cologne);
  francfort.getMoyens()[ROUTE].addDesserte(&munich);
  francfort.getMoyens()[AVION].addDesserte(&londres);

  munich.getMoyens()[ROUTE].addDesserte(&francfort);
  munich.getMoyens()[TRAIN].addDesserte(&strasbourg);
  munich.getMoyens()[AVION].addDesserte(&geneve);

  geneve.getMoyens()[TRAIN].addDesserte(&lyon);
  geneve.getMoyens()[AVION].addDesserte(&munich);

  milan.getMoyens()[TRAIN].addDesserte(&lyon);
  milan.getMoyens()[ROUTE].addDesserte(&florence);

  florence.getMoyens()[ROUTE].addDesserte(&milan);
  florence.getMoyens()[ROUTE].addDesserte(&rome);

  Transports r(ROUTE),t(TRAIN),b(BATEAU),a(AVION);

  p.deplace(&nantes);
  p.deplace(&brest,t);
  p.deplace(&bordeaux,b);
  p.deplace(&munich,t);
  p.deplace(&cologne,a);
  p.deplace(&cologne,r);
  p.deplace(&paris);
  p.deplace(&paris,t);

  

  

  
}

void testArray(void){
  Array<int> *a = new Array<int>();
  for(int i = 0 ; i < 12 ; i++){
    a->add(i);
  }

  a->remove(5);
  a->remove(9);
  a->remove(3);
  int i = 0;
  while(a->get(i) != NULL){
    std::cout << *a->get(i) << std::endl;
    i++;
  }
  delete a;
}
