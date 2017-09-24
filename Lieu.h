#ifndef LIEU_H
#define LIEU_H

#include <iostream>
#include <queue>
#include "Array.h"
#include "value.h"
#include "Transports.h"
//class Transports;

class Lieu {
 private:
  long id;
  static Array<Lieu *> listLieu;
  std::string nom;
  Transports moyens[NB_TRANSPORTS];
  long nbMoyen;
 public:
 
  Transports * getMoyens();
  Lieu();
  ~Lieu();
  Lieu(std::string n);
  std::string getNom(void);//public
  long getNbMoyen(void);//public ou supp
  Lieu * getAccessible(std::string mode, long n);//public
  bool estAccessible(Transports mt, Lieu * l);
  long distance(Moyen mt, Lieu * l);
};

#endif
