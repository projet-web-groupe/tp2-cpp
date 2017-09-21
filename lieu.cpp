#include "Lieu.h"
#include "Transports.h"

Lieu::Lieu(std::string n) : nom(n), nbMoyen(-1){
  id = nbLieu++;
  list.push_back(this);
  moyens[ROUTE] = Transports(ROUTE);
  moyens[TRAIN] = Transports(TRAIN);
  moyens[AVION] = Transports(AVION);
  moyens[BATEAU] = Transports(BATEAU);
}

Lieu::Lieu() : nom("null part"), moyens(NULL), nbMoyen(-1){
  id = nbLieu++;
  list.push_back(this);
}

Lieu::~Lieu(){
  for(vector<Lieu *>::iterator it = list.begin() ; it != list.end;it++)
    if(it->id == this.id)
      erase(it);
}

std::string Lieu::getNom(){
  return nom;
}

long Lieu::getNbMoyen(void){
  return nbMoyen;
}

long Lieu::getId(){
  return id;
}

Lieu * Lieu::chercher(long id){
  Lieu * res = NULL;
  vector<Lieu *>::iterator it = list.begin();
  while(it != list.end && it->id != id)
    it++;
  if(it->id == this.id)
    res = &(*it);
  return res;
}

Moyen Lieu::strToMoyen(std::string s){
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

std::string Lieu::moyenToStr(Moyen m){
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

Lieu * Lieu::getAccessible(std::string mode, long n){
  Moyen m = strToMoyen(mode);
  Transport t = moyens[m];
  Lieu * res = NULL;
  if(n < t.getDesserteSize())
    res = t.desserte[n];
  return res;
}
