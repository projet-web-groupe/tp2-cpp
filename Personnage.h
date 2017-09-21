#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>


class Personnage {
 private:
  std::string nom;
 public:
  Personnage();
  Personnage(std::string n);
  ~Personnage();
  void parle(std::string text);
};

#endif
