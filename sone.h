#ifndef __SONER_H
#define __SONER_H

#include "ListTool2B.h"
#include "const.h"
#include <iostream>
#include <fstream>

using namespace std;

class Sone : public TextElement {
private:
	char * sonenavn; //Unikt sonenavn
	int antBill, antSolgt, pris; //Antall billetter til salgs, Antall solgt og pris
	char type;
public:
	void display();
	Sone();
	Sone(char * t);
	Sone(Sone* s);
	virtual char hentType();
};

#endif