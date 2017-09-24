#ifndef HERITIERE_H
#define HERITIERE_H

#include <string>
#include "Personnage.h"
#include <iostream>

class Heritiere : Personnage{
  bool captive;
 public:
  Heritiere(Lieu * p, std::string n = "noName");
  void setCaptive(bool b);
}

#endif
