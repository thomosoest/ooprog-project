#ifndef __STEDER_H
#define __STEDER_H


#include "ListTool2B.h"
#include "sted.h"

class Steder {

private:

	List * stedListe;												

public:

	Steder();							//
	void meny(char valg);				//
	void nyttSted();					//
	void displaySted();					//
	void lesFraFilSteder();				//
	void skrivTilFilSteder();			//
	void nyttOppsett();					//
	void displayOppsett();				//
	List* kopier(char* nvn, int nr);	//
	bool finnesSted(char * nvn);		//Tar navn som parameter og returnerer true eller false om sted finnes
};


#endif

