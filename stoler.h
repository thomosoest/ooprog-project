#ifndef __SONE_H
#define __SONE_H

#include "sone.h"
#include <iostream>
#include "const.h"
#include <fstream>

using namespace std;



class Stoler : public Sone {
private:
	int billetter[RAD][REKKE];   //Maks rad og rekker
	int rad, rekke;			
	char type;				//Om stoler eller vrimle
	
public:
	 void display();		//Displayfunksjon
	 Stoler(char * t);		//Constructor om lager nytt objekt manuelt
	 Stoler(Stoler & s);	//Constructor om kopiering av objekt
	 char hentType();		//Returnerer om stoler eller vrimle
	 void skrivTilfil(ofstream & utfil);
	 Stoler(char t[], ifstream & innfil);
	 int hentantbill();		//virituell som returerer antBill
	 void kjop(int kjop, int knr, char * nvn); //Virituell som gjennomforer kjop
	 void billettTilFil(ofstream & utfil, int a);
	 


	
};
#endif
