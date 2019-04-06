#ifndef __SONE_H
#define __SONE_H

#include "sone.h"
#include <iostream>
#include "const.h"
#include <fstream>

using namespace std;



class Stoler : public Sone {
private:
	int kundenr;			//Kundenr til de som har kjopt billetter
	int sete[RAD][REKKE];   //Maks rad og rekker
	int rad, rekke;
	char type;				//Om stoler eller vrimle
	
public:
	 void display();		//Displayfunksjon
	 Stoler(char * t);		//Constructor om lager nytt objekt manuelt
	 Stoler(Stoler & s);	//Constructor om kopiering av objekt
	 char hentType();		//Returnerer om stoler eller vrimle
	 void skrivTilfil(ofstream & utfil);
	 Stoler(char t[], ifstream & innfil);
	 void hentSete(int radS, int rekkeS);
	
};
#endif
