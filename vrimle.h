#ifndef __Sone_H
#define __Sone_H

#include "funksjoner.h"
#include "sone.h"
#include "const.h"
#include <fstream>

using namespace std;

class Vrimle : public Sone {
private:
	int kundenr[ANTVRIMLE];		//Kundenr til de som har kjopt billetter
	char type;					//Om stoler eller vrimle

public:
	void display();				//Displayfunksjon
	Vrimle(char * t);			//Constructor om lager nytt objekt manuelt
	Vrimle(Vrimle & v);			//Constructor om kopiering av objekt
	char hentType();			//Returnerer om stoler eller vrimle
	void skrivTilfil(ofstream & utfil);
	Vrimle(char t[], ifstream & innfil);
	
};
#endif
