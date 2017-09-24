#ifndef GANSTERS_H
#define GANSTERS_H

#include <string>
#include "Personnage.h"
#include <iostream>

class Ganster : Personnage{
  std::string gang;
  int recompense;
  bool enPrison;
  int butin;
 public :
  Ganster(Lieu * p,std::string n ="noName",std::string g="");
  
}

#endif
