#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>
#include "Lieu.h"
#include "Transports.h"

class Personnage {
 protected:
  std::string nom;
  Lieu * pos;
  void action();
 public:
  Personnage(Lieu * p);
  Personnage(std::string n, Lieu * p);
  ~Personnage();
  void parle(std::string text);
  void deplace(Lieu * l);
  void deplace(Lieu * l, Transports t);
  void setPos(Lieu * l);
};

#endif
