#ifndef GANGSTERS_H
#define GANGSTERS_H

#include <string>
#include <iostream>
#include "Personnage.h"
#include "Array.h"

class Heritiere;
class Policier;

class Gangster : public Personnage{
  std::string gang;
  int recompense;
  bool enPrison;
  int butin;
  Array<Heritiere *> detenu;
 public :
  static Array<Gangster *> listGangster;
  Gangster(Lieu * p,std::string n ="noName",std::string g="");
  //Accesseurs
  std::string getGang();
  bool getEnPrison();
  int getButin();
  int getRecompense();
  void setGang(std::string g);
  void setEnPrison(bool b);
  void setButin(int n);
  void setRecompense(int);
  Array<Heritiere *> getDetenu();

  void corruptionOK(std::string nomP);
  void fuiteAttaque(void);

  void enleve(Heritiere& d);
  void estCapture(Policier& c);
  void sEvade();
  void augmenteRecompense();
  void effaceRecompense();

  void action();
};

#endif
