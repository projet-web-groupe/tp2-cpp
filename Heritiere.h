#ifndef HERITIERE_H
#define HERITIERE_H

#include "Array.h"
#include "Personnage.h"

class Policier;

class Heritiere : public Personnage{
  bool captive;
 public:
  static Array<Heritiere *> listHeritiere;
  Heritiere(Lieu * p, std::string n = "noName");
  ~Heritiere();
  void setCaptive(bool b);
  bool getCaptive(void);

  void estEnlevee(void);
  void estLiberee(Policier& c);
  void action();
};

#endif
