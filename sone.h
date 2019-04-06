#ifndef __SONER_H
#define __SONER_H

#include "ListTool2B.h"
#include "const.h"
#include <iostream>
#include <fstream>

using namespace std;

class Sone : public TextElement {

protected:										//for at Stoler og Vrimle kan bruke skriv til fil

	int antBill, antSolgt, pris;				//Antall billetter til salgs, Antall solgt og pris
	char type;									//Sone eller vrimle
public:
	void display();
	Sone();
	Sone(char * t);
	Sone(Sone* s);
	Sone(char t[], ifstream & innfil);
	virtual char hentType();					//virtuell som leser inn om det er sone eller vrimle
	char * hentNavn();							//returnerer navn paa sone
	void virtual skrivTilfil(ofstream & utfil); //Virtuell som skriver til fil
	int virtual hentPlasser(int i);

};

#endif