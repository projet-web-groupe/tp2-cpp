#ifndef LIEU_H
#define LIEU_H

#include <vector>
#include "value.h"
typedef int Moyen;

class Transports;

class Lieu {
  long id;
  std::string nom;
  long nbMoyen;
  Transports moyens[NB_TRANSPORTS];
 public:
  static long nbLieu = 0;
  static std::vector<Lieu *> list;
  static Lieu * chercher(long id);
  Lieu(std::string n);
  Lieu();
  ~Lieu();
  long Lieu::getNbMoyen(void);
  std::string getNom();
  long getId();
  Lieu* getAccessible(std::string mode, long n);
  Moyen strToMoyen(std::string s);
  std::string moyenToStr(Moyen m);
};

#endif
