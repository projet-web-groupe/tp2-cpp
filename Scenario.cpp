#include "Scenario.h"
#include "Array.h"
#include "Personnage.h"
#include "Heritiere.h"
#include "Policier.h"
#include "Gangster.h"
#include "Lieu.h"
#include <string>

Scenario::Scenario(){
	Lieu *chicago = new Lieu("Chicago","IL"),
	*indianapolis = new Lieu("Indiannapolis","IN"),
	*grandRapids = new Lieu("Grand Rapids","MI"),
	*cincinnati = new Lieu("Cincinnati","OH"),
	*toledo = new Lieu("Toledo","OH"),
	*detroit = new Lieu("Detroit","MI"),
	*colombus = new Lieu("Colombus","OH"),
	*cleveland = new Lieu("Cleveland","OH"),
	*pittsburgh = new Lieu("Pittsburgh","PA"),
	*buffalo = new Lieu("Buffalo","NY"),
	*philadelphie = new Lieu("Philladelphie","PA"),
	*newYork = new Lieu("New York","NY"),
	*albany = new Lieu("Albany","NY");

	chicago->getMoyens()[AVION].addDesserte(newYork);
	chicago->getMoyens()[AVION].addDesserte(philadelphie);
	chicago->getMoyens()[TRAIN].addDesserte(toledo);
	chicago->getMoyens()[TRAIN].addDesserte(cincinnati);
	chicago->getMoyens()[BATEAU].addDesserte(grandRapids);
	chicago->getMoyens()[ROUTE].addDesserte(indianapolis);

	indianapolis->getMoyens()[ROUTE].addDesserte(chicago);
	indianapolis->getMoyens()[ROUTE].addDesserte(cincinnati);
	indianapolis->getMoyens()[ROUTE].addDesserte(colombus);
	indianapolis->getMoyens()[AVION].addDesserte(newYork);

	grandRapids->getMoyens()[BATEAU].addDesserte(chicago);
	grandRapids->getMoyens()[ROUTE].addDesserte(detroit);

	cincinnati->getMoyens()[ROUTE].addDesserte(indianapolis);
	cincinnati->getMoyens()[ROUTE].addDesserte(colombus);
	cincinnati->getMoyens()[ROUTE].addDesserte(toledo);
	cincinnati->getMoyens()[TRAIN].addDesserte(chicago);
	cincinnati->getMoyens()[TRAIN].addDesserte(cleveland);
	cincinnati->getMoyens()[AVION].addDesserte(pittsburgh);
	cincinnati->getMoyens()[AVION].addDesserte(philadelphie);

	toledo->getMoyens()[ROUTE].addDesserte(detroit);
	toledo->getMoyens()[ROUTE].addDesserte(cincinnati);
	toledo->getMoyens()[ROUTE].addDesserte(cleveland);
	toledo->getMoyens()[TRAIN].addDesserte(chicago);
	toledo->getMoyens()[TRAIN].addDesserte(cleveland);
	toledo->getMoyens()[BATEAU].addDesserte(cleveland);

	detroit->getMoyens()[ROUTE].addDesserte(grandRapids);
	detroit->getMoyens()[ROUTE].addDesserte(toledo);
	detroit->getMoyens()[AVION].addDesserte(newYork);

	colombus->getMoyens()[ROUTE].addDesserte(indianapolis);
	colombus->getMoyens()[ROUTE].addDesserte(cincinnati);
	colombus->getMoyens()[ROUTE].addDesserte(cleveland);
	colombus->getMoyens()[ROUTE].addDesserte(pittsburgh);

	cleveland->getMoyens()[ROUTE].addDesserte(toledo);
	cleveland->getMoyens()[ROUTE].addDesserte(colombus);
	cleveland->getMoyens()[ROUTE].addDesserte(pittsburgh);
	cleveland->getMoyens()[TRAIN].addDesserte(toledo);
	cleveland->getMoyens()[TRAIN].addDesserte(cincinnati);
	cleveland->getMoyens()[BATEAU].addDesserte(toledo);
	cleveland->getMoyens()[BATEAU].addDesserte(buffalo);
	cleveland->getMoyens()[AVION].addDesserte(newYork);

	pittsburgh->getMoyens()[ROUTE].addDesserte(colombus);
	pittsburgh->getMoyens()[ROUTE].addDesserte(cleveland);
	pittsburgh->getMoyens()[ROUTE].addDesserte(philadelphie);
	pittsburgh->getMoyens()[TRAIN].addDesserte(philadelphie);
	pittsburgh->getMoyens()[AVION].addDesserte(cincinnati);

	buffalo->getMoyens()[ROUTE].addDesserte(albany);
	buffalo->getMoyens()[TRAIN].addDesserte(newYork);
	buffalo->getMoyens()[BATEAU].addDesserte(cleveland);

	philadelphie->getMoyens()[ROUTE].addDesserte(pittsburgh);
	philadelphie->getMoyens()[ROUTE].addDesserte(newYork);
	philadelphie->getMoyens()[TRAIN].addDesserte(pittsburgh);
	philadelphie->getMoyens()[TRAIN].addDesserte(newYork);
	philadelphie->getMoyens()[AVION].addDesserte(cincinnati);
	philadelphie->getMoyens()[AVION].addDesserte(chicago);
	philadelphie->getMoyens()[AVION].addDesserte(newYork);

	newYork->getMoyens()[ROUTE].addDesserte(albany);
	newYork->getMoyens()[ROUTE].addDesserte(philadelphie);
	newYork->getMoyens()[TRAIN].addDesserte(buffalo);
	newYork->getMoyens()[TRAIN].addDesserte(philadelphie);
	newYork->getMoyens()[AVION].addDesserte(detroit);
	newYork->getMoyens()[AVION].addDesserte(chicago);
	newYork->getMoyens()[AVION].addDesserte(philadelphie);
	newYork->getMoyens()[AVION].addDesserte(indianapolis);
	newYork->getMoyens()[AVION].addDesserte(cleveland);

	albany->getMoyens()[ROUTE].addDesserte(buffalo);
	albany->getMoyens()[ROUTE].addDesserte(newYork);

	listLieu.add(chicago);
	listLieu.add(indianapolis);
	listLieu.add(grandRapids);
	listLieu.add(cincinnati);
	listLieu.add(toledo);
	listLieu.add(detroit);
	listLieu.add(colombus);
	listLieu.add(cleveland);
	listLieu.add(pittsburgh);
	listLieu.add(buffalo);
	listLieu.add(philadelphie);
	listLieu.add(newYork);
	listLieu.add(albany);
}

void Scenario::scene(void) {
	Personnage * p;
	for(long i = 0 ; i < listPerso.getSize() ; i++){
		p = *listPerso.get(i);
		p->deplaceAleatoire();
	}

	for(long i = 0 ; i < listPerso.getSize() ; i++){
		p = *listPerso.get(i);
		p->action();
	}
}

void Scenario::addPerso(Personnage *p){
	listPerso.add(p);
}