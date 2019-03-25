#ifndef __ARRANGEMENTER_H
#define __ARRANGEMENTER_H


#include "ListTool2B.h"
#include "arrangement.h"


class Arrangementer {



private:

	int sisteArrangement;
	List * arrangementListe;

public:


	Arrangementer();
	void nyArrangement();
	void meny();
	void displayArrangement();
	// void endreArrangement();
	void slettArrangement();
	void kjopBillett();

	//Display funksjonene:
	
	void displayTekst();
	void displaySted();
	void displayDato();
	void displayType();
	void displayArtist();
	void displayBillett();

	//void lesFil();
};


#endif 


/*
		<< "2: Hele eller deler av en tekst\n"
		<< "3: Displayes via Sted\n"
		<< "4: Gitt dato\n"
		<< "5: Gitt type\n"
		<< "6: Gitt artist\n"
		<< "7: Alle data inkludert billettsalg paa ett arrangement\n";
*/