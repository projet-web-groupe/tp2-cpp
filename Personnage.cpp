#include "Personnage.h"
#include "Transports.h"
#include "Lieu.h"
#include <string>

Personnage::Personnage(Lieu * p) : nom("noName"), pos(p)
{
  std::cout << "Bonjour, je suis " << nom  << " et je viens d'arriver à " << pos->getNom()  << "." << std::endl;
}

Personnage::Personnage(std::string n, Lieu * p) : nom(n), pos(p)
{
  std::cout << "Bonjour, je suis " << nom  << " et je viens d'arriver à " << pos->getNom() << "." << std::endl;
}

Personnage::~Personnage()
{
  std::cout << "Il n'y a plus rien à faire ici pour moi, " << nom  << ". Adieu"<< std::endl;
}

void Personnage::parle(std::string text){
  std::cout << nom << " : " << text << std::endl;
}

void Personnage::setPos(Lieu * l){
  if(l != NULL)
    pos = l;
}

void Personnage::deplace(Lieu * l){
  long d = pos->distance(ROUTE,l);
  if(d == -1)
    std::cout << "Zut je ne peut pas accéder à ce lieu par la route" << std::endl;
  else {
    setPos(l);
    std::cout << "Je vais à " << pos->getNom() << " en faisant " << d << " pas." << std::endl; 
  }
}

void Personnage::deplace(Lieu * l, Transports t){
  long d = pos->distance(t.getMode(),l);
  if(d == -1)
    std::cout << "Zut je me suis trompé de " << Transports::moyenToStr(t.getMode()) << "." << std::endl;
  else {
    setPos(l);
    std::cout << "Je vais à " << pos->getNom() << " par le " << Transports::moyenToStr(t.getMode()) << std::endl; 
  }
}

void Personnage::deplaceAleatoire(void){
  srand(time(NULL));
  int r = randInt(0,5);
  long s;
  Lieu * dest;
  switch(r){
    case(ROUTE):
    //prendre la route
    s = pos->getMoyens()[ROUTE].getArray().getSize();
    if(s > 0){
      dest = pos->getAccessible(ROUTE_STR, rand()%s);
      deplace(dest,pos->getMoyens()[ROUTE]);
    }
    else
      r = AUCUN;
    break;
    case(TRAIN):
    //prendre le train
    s = pos->getMoyens()[TRAIN].getArray().getSize();
    if(s > 0){
      dest = pos->getAccessible(TRAIN_STR, rand()%s);
      deplace(dest,pos->getMoyens()[TRAIN]);
    }
    else
      r = AUCUN;
    break;
    case(BATEAU):
    //prendre le bateau
    s = pos->getMoyens()[BATEAU].getArray().getSize();
    if(s > 0){
      dest = pos->getAccessible(BATEAU_STR, rand()%s);
      deplace(dest,pos->getMoyens()[BATEAU]);
    }
    else
      r = AUCUN;
    break;
    case(AVION):
    //prendre l'avion
    s = pos->getMoyens()[AVION].getArray().getSize();
    if(s > 0){
      dest = pos->getAccessible(AVION_STR, rand()%s);
      deplace(dest,pos->getMoyens()[AVION]);
    }
    else
      r = AUCUN;
    break;
    default:
    //ne pas bouger
    ;
  }
}

double Personnage::randDouble(double min, double max){
  srand(time(NULL));
  return min+ (max-min)*((double)rand()/(double)RAND_MAX);
}

int Personnage::randInt(int min, int max){
  srand(time(NULL));
  return min + rand()%(max - min);
}

Lieu * Personnage::getPos(void){
  return pos;
}

std::string Personnage::getNom(void){
  return nom;
}

void Personnage::action(){
  
}