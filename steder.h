#ifndef __STEDER_H
#define __STEDER_H


#include "ListTool2B.h"
#include "sted.h"

class Steder {

private:

	List * stedListe;												

public:

	Steder();							//Constructor
	void meny(char valg);				//Meny som tar inn valg fra main
	void nyttSted();					//Lager ett nytt sted
	void displaySted();					//Displayfunksjon for sted
	void lesFraFil();					//Les fra fil funksjon
	void skrivTilFil();					//Skriv til fil funksjon
	void nyttOppsett();					//Lager ett nytt oppsett
	void endreOppsett();				//Endrer paa oppsett
	void displayOppsett();				//Displayfunksjon for oppsett
	List* kopier(char* nvn, int nr);	//Kopieringsfunksjon for oppsett
	bool finnesStedOgOps(char * nvn,int i);		//Tar navn som parameter og returnerer true eller false om sted finnes
	


	
};


#endif

