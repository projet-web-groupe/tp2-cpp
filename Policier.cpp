#include "Policier.h"
#include "Heritiere.h"
#include "Gangster.h"
#include <string>
#include <cmath>
#include <iostream>

Policier::Policier(Lieu * p, Lieu * base, std::string n) : Personnage(n,p), qg(base), reputation(0),argent(0){
}

Lieu * Policier::getQg(void){
  return qg;
}

int Policier::getReputation(void){
  return reputation;
}

int Policier::getArgent(void){
  return argent;
}

void Policier::setQg(Lieu * base){
  qg = base;
}

void Policier::setReputation(int n){
  reputation = n;
}

void Policier::setArgent(int a){
  argent = a;
}

void Policier::action(void){
  Gangster * g;
  for(int i = 0; i < Gangster::listGangster.getSize() ; i++){
    g = *Gangster::listGangster.get(i);
    if(pos == g->getPos()){
      attaque(*g);
    }
  }
}


void Policier::libere(Heritiere& d){
  d.setCaptive(false);
}

void Policier::attaque(Gangster& b){
  std::cout << b.getNom() << ", sortez les mains en l’air !" << std::endl;
  double probaArrestation = pow(0.75,(double)1/(double)(reputation + 1)) * (1 - pow(0.75, 10/(double)b.getRecompense()));
  if(randDouble(0,1) < probaArrestation){
    incrementePopularite();
    //capture
    b.estCapture(*this);

    //liberation heritiere potentiellement enlevée
    long i = 0;
    bool test = true;
    Array<Heritiere*> det = b.getDetenu();
    while(det.get(i) != NULL){
      Heritiere * h = *(det.get(i));

      libere(*h);
      h->estLiberee(*this);
      incrementePopularite();
      det.remove(h);
      i++;
      test = false;
    }

    double probaCorruption = 1 - pow(0.75,(double)1/(double)(reputation + 1));
    if(test){
      //si pas otage
      if(b.getButin() >= 3*b.getRecompense() && randDouble(0,1) < probaCorruption){
      //si corruption OK
        int s = ((long)(( ((double)2)/((double)3) ) * b.getButin()))%10;
        argent += s;
        //perte reputation
        reputation = 0;
        //actualisation butin
        b.setButin(b.getButin() - s);
        //affichage msg gangster;
        b.corruptionOK(nom);
      }
      else{
        //si corruption KO
        std::cout << "Misérable " << b.getNom() << ", tu me crois aussi cupide et malfaisant que toi ?" << std::endl;
        incrementePopularite();
        //empoche recompense
        argent += b.getRecompense();
        //remise a zero recompense
        b.effaceRecompense();
        //confisque butin
        b.setButin(0);
      }
    }
    else{
      //empoche recompense
      argent += b.getRecompense();
      //remise a zero recompense
      b.setRecompense(0);
      //confisque butin
      b.setButin(0);
    }
  }
  else{
    decrementePopularite();
    //affichage msg Gangster
    b.fuiteAttaque();
    //std::cout << "Tu crois vraiment pouvoir vaincre le gang "<< g.getGang() <<" ?" << std::endl;
    

    
  }
}

void Policier::incrementePopularite(){
  reputation++;
}

void Policier::decrementePopularite(){
  if (reputation > 0)
    reputation--;
}
