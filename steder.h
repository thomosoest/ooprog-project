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
	void lesFraFilSteder();				//
	void skrivTilFilSteder();			//
	void nyttOppsett();					//Lager ett nytt oppsett
	void displayOppsett();				//Displayfunksjon for oppsett
	List* kopier(char* nvn, int nr);	//Kopieringsfunksjon for oppsett
	bool finnesSted(char * nvn);		//Tar navn som parameter og returnerer true eller false om sted finnes
};


#endif

