#ifndef TRANSPORTS_H
#define TRANSPORTS_H
#include <string>
#include "value.h"

#define PAGE 10
typedef int Moyen;
class Lieu;

class Transports {

 public:

  Lieu ** desserte;
  Moyen mode;
  
  Transports(int mod);
  Transports();
  void addDesserte(Lieu * l);
  void removeDesserte(Lieu * l);
  long getDesserteSize();

 private:
  long desserteSize;
  long desserteSizeMax;
};

#endif
