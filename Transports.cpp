#include "Transports.h"
#include "Lieu.h"

Transports::Transports() : mode(AUCUN){
}

Transports::Transports(Moyen mod) : mode(mod) {
}

void Transports::addDesserte(Lieu *l){
  desserte.add(l);
}

void Transports::removeDesserte(Lieu *l){
  desserte.remove(l);
}

Array<Lieu*> Transports::getArray(){
  return desserte;
}

Moyen Transports::getMode(){
  return mode;
}

Moyen Transports::strToMoyen(std::string s){
  if(s == ROUTE_STR)
    return  ROUTE;
  else if (s == TRAIN_STR)
    return  TRAIN;
  else if (s == AVION_STR)
    return  AVION;
  else if (s == BATEAU_STR)
    return  BATEAU;
  else
    return AUCUN;
}


std::string Transports::moyenToStr(Moyen m){
  switch(m){
  case (ROUTE):
    return  ROUTE_STR;
  case (TRAIN):
    return  TRAIN_STR;
  case (AVION):
    return  AVION_STR;
  case (BATEAU):
    return  BATEAU_STR;
  default :
    return AUCUN_STR;
  }
}
