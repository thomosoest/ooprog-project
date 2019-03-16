#ifndef __KUNDE_H
#define __KUNDE_H

#include "ListTool2B.h"

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
	void display();
	bool riktigNavn(char* nvn);


};
#endif

