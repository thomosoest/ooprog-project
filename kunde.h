#ifndef __KUNDE_H
#define __KUNDE_H

#include "ListTool2B.h"
#include <fstream>


using namespace std;

class Kunde : public NumElement{

private:

	char* navn;
	char* gateadr;
	char* poststed;
	char* mail;
	int tlf;
	int postnr;
	int id;

public:

	Kunde(int n);
	Kunde(int n, ifstream & innfil);

	void endreKunde();	//Meny for aa endre kundedata
	void display();		//Displayer data
	bool riktigNavn(char* nvn);			//Returnerer true eller false om navnet er identisk til parameter
	void skrivFil(ofstream & utfil);	//Skriver til fil
	
};

#endif