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

	void display();
	bool riktigNavn(char* nvn);
	void skrivFil();
};

#endif