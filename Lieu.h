#ifndef LIEU_H
#define LIEU_H

#include <iostream>
class Transports;

class Lieu {
 private:
  std::string nom;
  Transports *moyens;
  long nbMoyen;
 public:
  Lieu();
  ~Lieu();
  Lieu(std::string n);
  std::string getNom(void);
  long getNbMoyen(void);
};

#endif
