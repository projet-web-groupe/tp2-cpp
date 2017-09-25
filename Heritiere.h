#ifndef HERITIERE_H
#define HERITIERE_H

#include <string>
#include "Personnage.h"
#include "time.h"
#include <iostream>

class Policier;

class Heritiere : public Personnage{
  bool captive;
 public:
  //static Array<Heritiere *> listHeritiere;
  Heritiere(Lieu * p, std::string n = "noName");
  void setCaptive(bool b);
  bool getCaptive(void);

  void estEnlevee(void);
  void estLiberee(Policier& c);
  void action();
};

#endif
