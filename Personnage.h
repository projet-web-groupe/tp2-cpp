#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Lieu.h"
#include <string>
#include "Transports.h"

class Personnage {
 protected:
  std::string nom;
  Lieu * pos;
  //virtual void action();
  int randInt(int min, int max);
  double randDouble(double min, double max);
 public:
  Personnage(Lieu * p);
  Personnage(std::string n, Lieu * p);
  ~Personnage();
  void parle(std::string text);
  void deplace(Lieu * l);
  void deplace(Lieu * l, Transports t);
  void setPos(Lieu * l);
  Lieu * getPos(void);
  std::string getNom(void);
};

#endif
