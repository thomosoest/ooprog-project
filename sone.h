#ifndef __SONER_H
#define __SONER_H

#include "ListTool2B.h"
#include "const.h"
#include <iostream>
#include <fstream>

using namespace std;

class Sone : public TextElement {
private:
	List * soneListe;
	char * sonenavn; //Unikt sonenavn
	int antBill, antSolgt, pris; //Antall billetter til salgs, Antall solgt og pris
public:
	virtual void display();
	void displayOppsett();
	void nyttOppsett();
	Sone();
	Sone(char * t);
};

#endif