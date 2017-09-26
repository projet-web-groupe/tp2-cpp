#ifndef LIEU_H
#define LIEU_H

#include "Array.h"
#include "value.h"
#include "Transports.h"

//class Transports;

class Lieu {
 private:
  long id;
  static Array<Lieu *> listLieu;
  std::string nom;
  std::string etat;
  Transports moyens[NB_TRANSPORTS];
  long nbMoyen;
 public:
 
  Transports * getMoyens();
  Lieu();
  ~Lieu();
  Lieu(std::string n, std::string e="");
  std::string getNom(void);
  long getNbMoyen(void);
  Lieu * getAccessible(std::string mode, long n);
  bool estAccessible(Transports mt, Lieu * l);
  long distance(Moyen mt, Lieu * l);
};

#endif
