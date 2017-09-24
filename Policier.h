#ifndef POLICIER_H
#define POLICIER_H

#include <string>
#include "Personnage.h"
#include <iostream>

class Policier : Personnage{
  Lieu * qg;
  int reputation;
 public:
  Policier(Lieu * p, Lieu * base, std::string n = "noName");
}

#endif
