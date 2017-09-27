#ifndef TRANSPORTS_H
#define TRANSPORTS_H

#include "value.h"
#include "Array.h"

class Lieu;

class Transports {
  Array<Lieu *> *desserte;
  Moyen mode;
 public:
  static Moyen strToMoyen(std::string s);
  static std::string moyenToStr(Moyen m);
  Transports(Moyen mod);
  Transports();
  ~Transports();
  void addDesserte(Lieu * l);
  void removeDesserte(Lieu * l);
  Array<Lieu *> getArray();
  Moyen getMode();
};

#endif
