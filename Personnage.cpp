#include "Personnage.h"

Personnage::Personnage(Lieu * p) : nom("noName"), pos(p)
{
  std::cout << "Bonjour, je suis " << nom << std::endl;
}

Personnage::Personnage(std::string n, Lieu * p) : nom(n), pos(p)
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