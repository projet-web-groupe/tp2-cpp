#ifndef POLICIER_H
#define POLICIER_H

#include "Personnage.h"

class Heritiere;
class Gangster;

class Policier : public Personnage{
  Lieu * qg;
  int reputation;
  int argent;
 public:
  Policier(Lieu * p, Lieu * base, std::string n = "noName");
  Lieu * getQg(void);
  int getReputation(void);
  int getArgent();
  void setQg(Lieu * base);
  void setReputation(int n);
  void setArgent(int a);
  void libere(Heritiere& d);
  void attaque(Gangster& b);
  void incrementePopularite();
  void decrementePopularite();
  void action();
};

#endif
