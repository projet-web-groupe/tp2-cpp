#include "Transports.h"
#include "Lieu.h"

Transports::Transports() : mode(AUCUN), desserte(NULL), desserteSize(-1), desserteSizeMax(0){
}
Transports::Transports(int mod) : mode(mod), desserte(NULL), desserteSize(-1), desserteSizeMax(0) {
}
void Transports::addDesserte(Lieu *l){
  if(desserte == NULL && desserteSize <= -1){
    desserte = new Lieu*[PAGE];
    desserteSize = 1;
    desserteSizeMax = PAGE;
    desserte[0] = l;
  }

  else if (desserte != NULL && desserteSize < desserteSizeMax)
    desserte[desserteSize-1] = l;

  else if (desserte != NULL && desserteSize == desserteSizeMax){
    Lieu ** temp = new Lieu* [desserteSize+10];
    for(int i = 0 ; i < desserteSize ; i++)
      temp[i] = desserte[i];
    delete[] desserte;
    desserte = temp;
    desserteSize++;
    desserte[desserteSize-1] = l;
  }
  else
    std::cout << "Erreur Gestion tableau desserte" << std::endl;
}

void Transports::removeDesserte(Lieu *l){
  if(desserte != NULL && desserteSize != -1){
    for(int i =0 ; i < desserteSize-1 ; i++)
      if(desserte[i] == l){
	for(int j = i; j < desserteSize ; j++)
	  desserte[j] = desserte[j+1];
	desserte[desserteSize-1] = NULL;
	desserteSize-1;
      }
  }
  else
  //Suppression des pages non necessaire sauf la première...
  if(desserte != NULL && desserteSizeMax != PAGE && (desserteSizeMax/PAGE - desserteSize/PAGE) != 0){
    long n = 10*((desserteSizeMax/10 - desserteSize/10)+1);
    Lieu ** temp = new Lieu*[n];
    for(int i = 0 ; i < desserteSize ; i++)
      temp[i] = desserte[i];
    delete[] desserte;
    desserte = temp;
  }
}

Lieu * Transports::getAccessible(std::string mode_arg, long n){
  Moyen m = strToMoyen(mode_arg);
  if (n >=0 && n < desserteSize && mode == m)
    return desserte[n];
  return NULL;
}

long Transports::getDesserteSize(){
  return desserteSize;
}
