#ifndef __KUNDER_H
#define __KUNDER_H


#include "ListTool2B.h"
#include "kunde.h"


class Kunder {



private:

	int sisteKunde;
	List * kundeListe;

public:


	Kunder();
	void nyKunde();			//Lager ny kunde
	void meny();			//Hovedmenyen
	void displayKunde();	//Ulike alternativer for aa skrive ut data
	void endreKunde();		//Endrer dataene til en kunde
	void lesFil();			//Les fra fil funksjon
	void skrivFil();		//Skriv til fil funksjon
	void slettKunde();		//Sletter en gitt kunde
};


#endif 
