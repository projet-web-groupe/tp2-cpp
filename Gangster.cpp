#include "Gangster.h"
#include "Heritiere.h"
#include "Policier.h"
#include "Personnage.h"
#include <string>
#include <iostream>

Array<Gangster *> Gangster::listGangster;

Gangster::Gangster(Lieu * p,std::string n,std::string g) : Personnage(p), gang(g), recompense(100), enPrison(false), butin(0){
  pos = p;
  nom = n;
  std::cout << "Je suis " << nom << ", membre du gang " << g << "."<<std::endl;
  listGangster.add(this);
}

std::string Gangster::getGang(){
  return gang;
}

bool Gangster::getEnPrison(){
  return enPrison;
}

int Gangster::getButin(){
  return butin;
}

int Gangster::getRecompense(){
  return recompense;
}

void Gangster::setGang(std::string g){
  gang = g;
}

void Gangster::setEnPrison(bool b){
  enPrison = b;
}

void Gangster::setButin(int n){
  butin = n;
}

void Gangster::setRecompense(int r){
  recompense = r;
}

Array<Heritiere *> Gangster::getDetenu(){
  return detenu;
}

void Gangster::corruptionOK(std::string nomP){
  std::cout << "Tu vois, " << nomP << ", je savais bien qu'on pourrait s'arranger..." << std::endl;
}

void Gangster::fuiteAttaque(void){
  enPrison = false;
  std::cout << "Tu crois vraiment pouvoir vaincre le gang " << gang <<" ?" << std::endl;
}

void Gangster::enleve(Heritiere& d){
  std::cout << d.getNom() << ", tu es maintenant à la merci du gang " << gang << " !" << std::endl;
  d.estEnlevee();
  detenu.add(&d);
}
void Gangster::estCapture(Policier& c){
  enPrison = true;
  setPos(c.getQg());
}
void Gangster::sEvade(){
  enPrison = false;
  recompense = 100;
}
void Gangster::augmenteRecompense(){
  recompense += 100;
}
void Gangster::effaceRecompense(){
  recompense = 0;
}

void Gangster::action()
{
  Heritiere * h;
  for(int i = 0; i < Heritiere::listHeritiere.getSize() ; i++){
    h = *Heritiere::listHeritiere.get(i);
    if(pos == h->getPos()){
      enleve(*h);
    }
  }
}