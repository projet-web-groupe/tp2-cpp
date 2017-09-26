#include "Lieu.h"
#include "Transports.h"
#include "Array.h"
#include "value.h"
#include <queue>
#include <string>


Array<Lieu *> Lieu::listLieu;

Lieu::Lieu(std::string n, std::string e) : nom(n),etat(e), nbMoyen(4){
  moyens[ROUTE] = Transports(ROUTE);
  moyens[TRAIN] = Transports(TRAIN);
  moyens[AVION] = Transports(AVION);
  moyens[BATEAU] = Transports(BATEAU);
  listLieu.add(this);
}

Lieu::Lieu() : nom("null part"),etat(""), nbMoyen(4){
  moyens[ROUTE] = Transports(ROUTE);
  moyens[TRAIN] = Transports(TRAIN);
  moyens[AVION] = Transports(AVION);
  moyens[BATEAU] = Transports(BATEAU);
  listLieu.add(this);
}

Lieu::~Lieu(){
  listLieu.remove(this);
}

std::string Lieu::getNom(){
  return nom;
}

long Lieu::getNbMoyen(void){
  return nbMoyen;
}

Lieu * Lieu::getAccessible(std::string mode, long n){
  Moyen m = Transports::strToMoyen(mode);
  if(m == AUCUN)
    return NULL;
  if(moyens[m].getArray().get(n) == NULL)
    return NULL;
  return *(moyens[m].getArray().get(n));
}

bool Lieu::estAccessible(Transports mt, Lieu *l){
  Moyen m = mt.getMode();
  if(m == AUCUN)
    return false;
  return moyens[m].getArray().search(l) != NULL;
}

long Lieu::distance(Moyen mt, Lieu * l){
  /*
    La fonction distance utilise une sorte de parcours en largeur du graphe.
    Le parcours s'arrete soit si la distance a été trouvé soit si la composante connexe courante a entièrement été visité (tenant compte du/des moyen(s) de transport(s) considéré(s))
   */
  int s = listLieu.getSize();
  int *marque = (int*)malloc(s*sizeof(int));
  for(long i = 0 ; i<s ; i++)
    marque[i] = -1;
  
  std::queue<Lieu *> q;
  q.push(this);
  marque[listLieu.getIndice(this)] = 0;
  
  while(!q.empty() && marque[listLieu.getIndice(l)] == -1){
    long i = 0;
    Lieu * temp = q.front()->getAccessible(Transports::moyenToStr(mt), i);
    while(temp != NULL){
      //parcours de tous les voisins atteignable par le moyens de transports mt et on les marque de la distance voulu s'il n'ont pas été déjà parcouru
      if(marque[listLieu.getIndice(temp)] == -1){
	marque[listLieu.getIndice(temp)] = marque[listLieu.getIndice(q.front())] + 1;
	q.push(temp);
      }
      //passage au voisin suivant
      temp = q.front()->getAccessible(Transports::moyenToStr(mt), ++i);
    }
    q.pop();
  }
  int res = marque[listLieu.getIndice(l)];
  free(marque);
  return res;
}

Transports * Lieu::getMoyens(){
  return moyens;
}
